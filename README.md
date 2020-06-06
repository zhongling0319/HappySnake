# HappySnake
一个QT实现的贪吃蛇小游戏

## 游戏界面

<img src="https://image-1301378304.cos.ap-nanjing.myqcloud.com/%E8%B4%AA%E5%90%83%E8%9B%87%E5%88%9D%E5%A7%8B%E7%95%8C%E9%9D%A2.png" alt="游戏初始界面" style="zoom:50%;" />

<img src="https://image-1301378304.cos.ap-nanjing.myqcloud.com/%E8%B4%AA%E5%90%83%E8%9B%87%E6%B8%B8%E6%88%8F%E7%95%8C%E9%9D%A2%E6%88%AA%E5%9B%BE.png" alt="贪吃蛇游戏界面" style="zoom: 50%;" />

<img src="https://image-1301378304.cos.ap-nanjing.myqcloud.com/GameOver%E6%88%AA%E5%9B%BE.png" alt="Game Over界面" style="zoom: 50%;" />

## 实现功能

- 传统贪吃蛇游戏，键盘“↑↓←→”控制蛇的方向
- 点击开始按钮开始游戏，随后开始按钮变为暂停，点击暂停可暂停游戏
- 游戏过程中点击重置按钮，即可重置为初始状态，得分清零
- 实现蛇运动速度的调整，关联滑块与选值框，二者同步控制速度
- 游戏实时显示得分，每吃到一次食物得分+1
- 蛇头碰到墙壁（边界）或自身则游戏结束，展示Game Over提示框
- Game Over提示框提供“再来一局”和“退出游戏”两个选项功能

