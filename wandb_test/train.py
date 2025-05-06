import wandb
import random
import time
import os

def train():
    # 1. 初始化 wandb
    wandb.init(project="wandb_test", entity=os.environ.get("WANDB_ENTITY"))
    
    # 2. 取超参数
    config = wandb.config
    learning_rate = config.learning_rate
    batch_size = config.batch_size
    
    print(f"[Train] Start training with learning_rate={learning_rate}, batch_size={batch_size}")
    
    # 3. 模拟训练
    loss = 100
    for epoch in range(5):
        # 假装loss下降一点，加上一点随机扰动
        loss = loss * (1 - learning_rate) + random.uniform(-0.5, 0.5)
        print(f"Epoch {epoch+1}, Loss: {loss:.4f}")
        
        # 4. log到wandb
        wandb.log({"epoch": epoch, "loss": loss})
        
        time.sleep(0.2)  # 假装训练时间

    print(f"[Train] Finish training.")

if __name__ == '__main__':
    train()
