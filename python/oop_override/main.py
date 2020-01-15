class Robot:
    def __init__(self, robot_name, life):
        self.name = robot_name
        self.life = life

    def sayHello(self, guest_name):
        print('Hello, ' + guest_name)

    def sayRobotName(self):
        print('My name is, ' + self.name)

class TakoyakiRobot(Robot):
    def __init__(self, robot_name, life):
        super().__init__(robot_name, life)

    def cookTakoyaki(self):
        print('たこ焼きを作りました')

class MyTakoyakiRobot(TakoyakiRobot):
    def __init__(self, robot_name, life):
        super().__init__(robot_name, life)

    # オーバーライド ... 親クラスのメソッドの上書き
    # ポリモーフィズム ... 同じメソッド名でもクラスによって振る舞いが違うこと. ポリモーフィズムの実現方法の１つがオーバーライド
    def cookTakoyaki(self):
        print('自分好みのたこ焼きにしました')

my_takoyaki_robot = MyTakoyakiRobot('たこ焼きロボット', 100)
my_takoyaki_robot.sayRobotName()
my_takoyaki_robot.sayHello('Kazukichi')
my_takoyaki_robot.cookTakoyaki()