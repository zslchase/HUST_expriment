import numpy as np
import pandas as pd
import adaboost.Adaboost as Ad
import mytest.test as Ts
X=pd.read_csv('data.csv',header=None).values
y=pd.read_csv('targets.csv',header=None).values
y=y.reshape(y.shape[0],1)
# 重新排序
index_shuffle = np.arange(len(X))
np.random.shuffle(index_shuffle)
X = X[index_shuffle]
y = y[index_shuffle]    
# 标准化
for index in range(len(X[0])):
    X[:, index] = (X[:, index] - np.min(X[:, index]))/(np.max(X[:, index])-np.min(X[:, index]))

base_op=[1,5,10,100]


print("请选择你的基分类器: 0是对数几率回归, 1是决策树")

op = int(input())


for base in base_op:
    print("基分类器数目：%d"%(base))
    for fold in range(0,10):
        print("第%d折"%(fold+1))
        num=int(len(X)/10)
        X_train=np.append(X[:fold*num,:],X[(fold+1)*num:,:],axis=0)
        y_train=np.append(y[:fold*num,:],y[(fold+1)*num:,:],axis=0)
        X_test=X[fold*num:(fold+1)*num,:]
        y_test=y[fold*num:(fold+1)*num,:]

        if op==1:
            y_train=y_train.reshape(len(y_train))
            y_test=y_test.reshape(len(y_test))

        Ada=Ad.myAdaBoost(base,op)
        Ada.fit(X_train,y_train)
        p1=Ada.predict(X_test)
        if op==1:
            # 将-1/1取值映射为0/1取值
            p1=(p1+1)/2
        
        data=[]
        for i in range(len(X_test)):
            d1=np.append(index_shuffle[fold*num+i],1 if p1[i] else 0)
            data.append(d1)
        pd.DataFrame(data).to_csv("experiments/base%d_fold%d.csv"%(base,fold+1),header=None,index=None)
print("Done!")

print("Begin Test!")

Ts.test_predict()