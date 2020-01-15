class Robot:
    # コンストラクタ
    # self ... 自分自身を参照する変数
    def __init__(self, robot_name, life):
        # self.nameとself.life ... 属性(プロパティ)
        self.name = robot_name
        self.life = life

    # メソッド ... クラスに属する関数(シグネチャーと呼ぶ言語もある)
    def sayHello(self, guest_name):
        print('Hello, ' + guest_name)

    def sayRobotName(self):
        print('My name is, ' + self.name)

# インスタンス化
my_robot = Robot('ロボット１号', 100)
my_robot.sayRobotName()
my_robot.sayHello('Kazukichi')