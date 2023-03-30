# -*- coding: utf-8 -*-
"""
Created on Sat Feb 26 15:06:20 2022

@author: Venkat Bhaskar
"""
import tensorflow as tf
import keras
from tensorflow.keras.datasets import mnist
import matplotlib.pyplot as plt
from tensorflow.keras.utils import to_categorical
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Conv2D
from tensorflow.keras import Sequential
from timeit import default_timer as timer
(trainX,trainy),(testX,testy)=mnist.load_data()
plt.imshow(trainX[1], cmap=plt.get_cmap('gray'))
trainX=trainX.reshape(60000,784)
testX=testX.reshape(10000,784)
trainy=to_categorical(trainy)
testy=to_categorical(testy)
trainX=trainX/255.0
testX=testX/255.0
start=timer()
def trainModel(model,epochs,optimizer):
  batch_size=128
  model.compile(optimizer=optimizer,
                loss='categorical_crossentropy',
                metrics='accuracy')
  return model.fit(trainX,trainy,validation_data=(testX,testy),epochs=epochs,batch_size=batch_size)
model=keras.models.Sequential([
                         keras.layers.Dense(512,activation='relu',input_shape=(784,)),
                         keras.layers.Dropout(0.2),
                         keras.layers.Dense(256,activation='relu'),
                         keras.layers.Dropout(0.2),
                         keras.layers.Dense(128,activation='relu'),
                         keras.layers.Dropout(0.2),
                         keras.layers.Dense(64,activation='relu'),
                         keras.layers.Dropout(0.2),
                         keras.layers.Dense(10,activation='softmax')
])
print(model.summary())
model_history=trainModel(model=model,epochs=20,optimizer='adam')
test_loss,test_acc=model.evaluate(testX,testy,batch_size=128)
end=timer()
s=end-start
print(s,'Seconds')