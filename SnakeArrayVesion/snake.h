#pragma once
/*蛇 爬行*/
void snakeMove();
/*能吃到 苹果
返回值：1 能 0 不能 */
int enabledEatApple();
/*蛇 长个了*/
void grow();
/*创建 新苹果*/
void createApple();

/*能咬自己
返回值：1 能 0 不能 */
int enabledEatSelf();


/*能出界
返回值：1 能 0 不能 */
int enabledOut();
/*游戏结束*/
void gameover();

/*转向 */
void turnLeft();
void turnRight();
void turnTop(); 
void turnBottom();