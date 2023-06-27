import numpy as np
import pandas as pd
import adaboost.Adaboost as Ad
def test_predict():
    #读入训练集
    X=pd.read_csv('data.csv',header=None).values
    y=pd.read_csv('targets.csv',header=None).values
    #读入测试集
    xx=pd.read_csv('test_data.csv',header=None).values
    ypp=pd.read_csv('test_label.csv',header=None).values
    ypp=ypp.reshape(len(ypp))
    #标准化
    for index in range(len(X[0])):
        X[:, index] = (X[:, index] - np.min(X[:, index]))/(np.max(X[:, index])-np.min(X[:, index]))
    for index in range(len(xx[0])):
        xx[:, index] = (xx[:, index] - np.min(xx[:, index]))/(np.max(xx[:, index])-np.min(xx[:, index]))
    y=y.reshape(len(y))
    #选择训练数据
    cnt=2
    num=int(len(X)/10)
    X_train=np.append(X[:cnt*num,:],X[(cnt+1)*num:,:],axis=0)
    y_train=np.append(y[:cnt*num],y[(cnt+1)*num:],axis=0)
    #训练，基分类器为决策树桩，数目10个
    Ada=Ad.myAdaBoost(10,1)
    Ada.fit(X_train,y_train)
    yy=(Ada.predict(xx)+1)/2
    #输出分数
    print(np.mean(yy==ypp))