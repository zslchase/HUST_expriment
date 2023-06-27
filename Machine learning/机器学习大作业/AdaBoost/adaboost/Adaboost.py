import Classifier.BaseDecisionTree as BD
import Classifier.BaseLogictic as BL
import numpy as np
class myAdaBoost:
    def __init__(self,n_estimators,Classify_type):
        self.n_estimators=n_estimators
        self.estimators=[]
        self.alphas=[]
        self.Classify_type=Classify_type

    def fit(self,X,y):
        sample_weights=np.ones(len(X))/len(X)
        if self.Classify_type==1:
            y = 2*y-1  # 将0/1取值映射为-1/1取值
            sample_weight = np.ones(len(X)) / len(X)  # 初始化样本权重为 1/N
            for _ in range(self.n_estimators):
                print(_)
                dec = BD.BaseDecisionTree().fit(X, y, sample_weight)  # 训练弱学习器
                alpha = 1/2 * np.log((1-dec.lowest_error)/dec.lowest_error)  # 权重系数
                y_pred = np.array(dec.predict(X))
                sample_weight *= np.exp(-alpha*y_pred*y)  # 更新迭代样本权重
                sample_weight /= np.sum(sample_weight)  # 样本权重归一化
                self.estimators.append(dec)
                self.alphas.append(alpha)
            return self
        else:
            for i in range(self.n_estimators):
                dec=BL.BaseLogistic(0.01,1000)
                dec.fit(X,y,sample_weights)
                y_predict=np.array(dec.predict(X))
                wr = np.zeros(X.shape[0])
                for i in range(0, wr.shape[0]):
                    if y_predict[i] != y[i]:
                        wr[i] = 1
                    else:
                        wr[i] = 0
                wr.reshape(X.shape[0], 1)
                ep = np.sum(wr * sample_weights)
                if ep >= 0.5:
                    ep = 1 - ep
                alpha =1/2* np.log((1.0 - ep) / ep)
                self.alphas.append(alpha)
                for i in range(0, X.shape[0]):
                    sample_weights[i] = sample_weights[i] * np.exp((1 if wr[i] else -1) * alpha)
                sample_weights = sample_weights / np.sum(sample_weights)
                self.estimators.append(dec)
                if ep == 0:
                    break

    def predict(self, X):
        y_pred = np.empty((len(X), len(self.estimators)))  # 预测结果二维数组，其中每一列代表一个弱学习器的预测结果
        sum_alphas=0
        for i in range(len(self.estimators)):
            y_pred[:, i] = self.estimators[i].predict(X)
            sum_alphas+=self.alphas[i]
        if self.Classify_type==1:
            return 2*(np.sum(y_pred, axis=1)>0)-1
        else:
            y_pred = y_pred * np.array(self.alphas)  # 将预测结果与训练权重乘积作为集成预测结果
            return np.sum(y_pred, axis=1)>(0.5*sum_alphas)