import numpy as np
class BaseLogistic:
    def __init__(self,lr,epochs):
        self.lr=lr 
        self.epochs=epochs
        self.weight=np.zeros(1)

    def sigmoid(self,z):
        return 1/(1+np.exp(-z))

    def fit(self,X,y,sample_weight):
        b = np.ones([X.shape[0], 1], dtype=float)
        X = np.concatenate((X, b), axis=1)
        n,p=X.shape
        self.weight=np.zeros(X.shape[1])
        self.weight=self.weight.reshape(X.shape[1],1)
        y = y.reshape(n,1)
        sample_weight=sample_weight.reshape(n,1)
        for epoch in range(self.epochs):
            yp=self.sigmoid(np.dot(X,self.weight))
            dw = np.dot(X.T, sample_weight*(yp - y))
            self.weight=self.weight-self.lr*dw
    
    def predict(self, X):
        b = np.ones((X.shape[0], 1), dtype=float)
        X = np.concatenate((X, b), axis=1)
        y_pred = self.sigmoid(np.dot(X, self.weight))
        y_pred1 = [1 if i>=0.5 else 0 for i in y_pred]
        return np.array(y_pred1)