import pandas as pd

from sklearn import datasets

iris = datasets.load_iris()
pd.set_option('display.max_columns', 4)
pd.set_option('display.max_rows', 150)
df = pd.DataFrame(iris.data, columns = iris.feature_names)
print(df)