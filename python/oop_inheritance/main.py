class Robot:
    def __init__(self, robot_name, life):
        self.name = robot_name
        self.life = life

    def sayHello(self, guest_name):
        print('Hello, ' + guest_name)

    def sayRobotName(self):
        print('My name is, ' + self.name)

# 継承するクラスはカッコ内に記述する
class TakoyakiRobot(Robot):
    def __init__(self, robot_name, life):
        # 親クラスのコンストラクタを呼び出す
        super().__init__(robot_name, life)

    def cookTakoyaki(self):
        print('たこ焼きを作りました')

my_takoyaki_robot = TakoyakiRobot('たこ焼きロボット', 100)
my_takoyaki_robot.sayRobotName()
my_takoyaki_robot.sayHello('Kazukichi')
my_takoyaki_robot.cookTakoyaki()