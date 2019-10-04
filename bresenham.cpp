#include "terminal.h"
#include "cmath"
#include "iostream"
#include <vector>

typedef struct 
{
    int x;
    int y;
}Point;

Point start_point = {15, 15};
Point end_point = {8, 0};

std::vector<Point> bresenham(Point start_point, Point end_point)
{
    std::vector <Point> res;
    Point pos = start_point;
    int direction_x = end_point.x - start_point.x;
    int direction_y = end_point.y - start_point.y;
    int delta_x = fabs(direction_x);
    int delta_y = fabs(direction_y);
    int max_xy = ((delta_x > delta_y) ? delta_x : delta_y);
    int decision_param_x = - (max_xy / 2);
    int decision_param_y = decision_param_x;

    res.push_back(start_point);
    for(int i = 0; i < max_xy; ++i)
    {
        //处理x
        decision_param_x += delta_x;
        if(decision_param_x > 0)
        {
            direction_x > 0 ? pos.x++ : pos.x--;
            decision_param_x -= max_xy;
        }
        
        //处理y
        decision_param_y += delta_y;
        if(decision_param_y > 0)
        {
            direction_y > 0 ? pos.y++ : pos.y--;
            decision_param_y -= max_xy;
        }
        res.push_back(pos);
    }
    return res;
}

int main(void)
{
    CLEAR();
    std::vector <Point> point = bresenham(start_point, end_point);
    for(int i = 0;i < point.size();i ++){
        // std::cout << xx[i].x << " " << xx[i].y << std::endl;
         GOTO_XY(point[i].x,point[i].y);
         std::cout << "*" << std::endl;
    }
     GOTO_XY(0,30);
    return 0;
}