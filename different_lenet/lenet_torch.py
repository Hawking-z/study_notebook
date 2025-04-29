import torch
import torch.nn as nn
import torch.nn.functional as F
from torch.utils.tensorboard import SummaryWriter
from torch.utils.data import DataLoader
from torchvision import datasets, transforms
import os
from utils import ROOT_DIR
from datetime import datetime
from tqdm import tqdm

import cv2 

def load_dataset(train=True):
    transform = transforms.Compose([transforms.ToTensor()])
    dataset = datasets.MNIST(root=ROOT_DIR+'/data', train=train, download=True, transform=transform)
    return dataset

def get_dataloader(train=True, batch_size=64):
    
    dataset = load_dataset(train)
    if train:
        dataloader = DataLoader(dataset, batch_size=batch_size, shuffle=True, num_workers=8,drop_last=True)
    else:
        dataloader = DataLoader(dataset, batch_size=batch_size, shuffle=False, num_workers=8)
    return dataloader
 
class LeNet(nn.Module):

    def __init__(self):
        super().__init__()
        self.model = nn.Sequential(
            nn.Conv2d(1, 6, kernel_size=5,padding=2),
            nn.ReLU(),
            nn.MaxPool2d(kernel_size=2, stride=2),
            nn.Conv2d(6, 16, kernel_size=5),
            nn.ReLU(),
            nn.MaxPool2d(kernel_size=2, stride=2),
            nn.Conv2d(16, 120, kernel_size=5),
            nn.ReLU(),
            nn.Flatten(),
            nn.Linear(120, 84),
            nn.ReLU(),
            nn.Linear(84, 10)
        )

    def forward(self, x):
        x = self.model(x)
        return x


def train_one_epoch(model, dataloader, optimizer, criterion, device, epoch, writer=None):
    model.train()
    running_loss = 0.0
    running_corrects = 0

    pbar = tqdm(dataloader, desc=f"Train Epoch {epoch+1}")

    for inputs, labels in pbar:
        inputs, labels = inputs.to(device), labels.to(device)

        optimizer.zero_grad()
        outputs = model(inputs)
        loss = criterion(outputs, labels)
        loss.backward()
        optimizer.step()

        running_loss += loss.item() * inputs.size(0)
        preds = outputs.argmax(dim=1)
        running_corrects += (preds == labels).sum().item()

    dataset_size = len(dataloader.dataset)
    epoch_loss = running_loss / dataset_size
    epoch_acc = running_corrects / dataset_size

    # TensorBoard log
    if writer:
        writer.add_scalar('Loss/train', epoch_loss, epoch)
        writer.add_scalar('Accuracy/train', epoch_acc, epoch)

    return epoch_loss, epoch_acc

def validate(model, dataloader, criterion, device, epoch, writer=None):
    model.eval()
    running_loss = 0.0
    running_corrects = 0

    with torch.no_grad():
        pbar = tqdm(dataloader, desc=f"Val Epoch {epoch+1}")

        for inputs, labels in pbar:
            inputs, labels = inputs.to(device), labels.to(device)

            outputs = model(inputs)
            loss = criterion(outputs, labels)

            running_loss += loss.item() * inputs.size(0)
            preds = outputs.argmax(dim=1)
            running_corrects += (preds == labels).sum().item()

    dataset_size = len(dataloader.dataset)
    epoch_loss = running_loss / dataset_size
    epoch_acc = running_corrects / dataset_size

    if writer:
        writer.add_scalar('Loss/val', epoch_loss, epoch)
        writer.add_scalar('Accuracy/val', epoch_acc, epoch)

    return epoch_loss, epoch_acc

def train(num_epochs,model, train_loader,test_loader, criterion, optimizer,writer, device):
    model = model.to(device)
    for epoch in range(num_epochs):
        train_loss, train_acc = train_one_epoch(model, train_loader, optimizer, criterion, device, epoch, writer)
        val_loss, val_acc = validate(model, test_loader, criterion, device, epoch, writer)

        print(f"[Epoch {epoch+1}] Train Loss: {train_loss:.4f}, Train Acc: {train_acc:.4f} | Val Loss: {val_loss:.4f}, Val Acc: {val_acc:.4f}")
    

if __name__ == "__main__":
    device = torch.device("cuda" if torch.cuda.is_available() else "cpu")
    print("Using device:", device)
    # Initialize TensorBoard writer
    log_root = os.path.join(ROOT_DIR, "logs")
    log_dir = os.path.join(log_root, datetime.now().strftime('%b%d_%H-%M-%S')+"_torch")
    writer = SummaryWriter(log_dir=log_dir)
    
    train_loader = get_dataloader(train=True, batch_size=64)
    test_loader = get_dataloader(train=False, batch_size=64)

    model = LeNet()
    crierion = nn.CrossEntropyLoss()
    optimizer = torch.optim.Adam(model.parameters(), lr=0.001)

    # Create a random input tensor with shape (1, 1, 28, 28)
    input_tensor = torch.randn(1, 1, 28, 28)

    # Perform a forward pass through the model
    output = model(input_tensor)

    # Add the model graph to TensorBoard
    writer.add_graph(model, input_tensor)

    # Train the model
    train(30, model, train_loader, test_loader, crierion, optimizer, writer, device)

    # Save the model
    torch.save(model.state_dict(), os.path.join(log_dir, "lenet_mnist.pth"))

    # Close the writer
    writer.close()