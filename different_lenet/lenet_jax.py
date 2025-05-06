import numpy as np
import jax.numpy as jnp

def load_mnist_images(filename):
    with open(filename, 'rb') as f:
        magic, num, rows, cols = np.frombuffer(f.read(16), dtype=np.uint32, count=4)
        magic = int.from_bytes(magic.tobytes(), byteorder='big')
        num = int.from_bytes(num.tobytes(), byteorder='big')
        rows = int.from_bytes(rows.tobytes(), byteorder='big')
        cols = int.from_bytes(cols.tobytes(), byteorder='big')
        images = np.frombuffer(f.read(), dtype=np.uint8).reshape(num, rows, cols)
        images = images.astype(np.float32) / 255.0  # 归一化到[0,1]
    return images

def load_mnist_labels(filename):
    with open(filename, 'rb') as f:
        magic, num = np.frombuffer(f.read(8), dtype=np.uint32, count=2)
        magic = int.from_bytes(magic.tobytes(), byteorder='big')
        num = int.from_bytes(num.tobytes(), byteorder='big')
        labels = np.frombuffer(f.read(), dtype=np.uint8)
    return labels

# 路径，替换成你自己的
train_images = load_mnist_images('./train-images-idx3-ubyte')
train_labels = load_mnist_labels('./train-labels-idx1-ubyte')
test_images = load_mnist_images('./t10k-images-idx3-ubyte')
test_labels = load_mnist_labels('./t10k-labels-idx1-ubyte')

# 转成JAX array（可选）
train_images = jnp.array(train_images)
train_labels = jnp.array(train_labels)
test_images = jnp.array(test_images)
test_labels = jnp.array(test_labels)

print(train_images.shape)  # (60000, 28, 28)
print(train_labels.shape)  # (60000,)
