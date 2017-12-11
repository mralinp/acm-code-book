#include <bits/stdc++.h>
#define MAX 1000
struct event
{
    int ind;   // Index of rectangle in rects
    bool type; // Type of event: 0 = Lower-left ; 1 = Upper-right
    event(){};
    event(int ind, int type) : ind(ind), type(type){};
};
struct point
{
    int x, y;
};
point rects[MAX][12]; 
// Each rectangle consists of 2 points: [0] = lower-left ; [1] = upper-right
bool compare_x(event a, event b)
{
    return rects[a.ind][a.type].x < rects[b.ind][b.type].x;
}
bool compare_y(event a, event b)
{
    return rects[a.ind][a.type].y < rects[b.ind][b.type].y;
    }
int union_area(event events_v[], event events_h[], int n, int e)
{
    /*n is the number of rectangles, e=2*n , e is the number of
    points (each rectangle has two points as described in 
    declaration of rects)
    */
    bool in_set[MAX] = {0};
    int area = 0;
    sort(events_v, events_v + e, compare_x);
    //Pre-sort of vertical edges
    sort(events_h, events_h + e, compare_y);
    // Pre-sort set of horizontal edges
    in_set[events_v[0].ind] = 1;
    for (int i = 1; i < e; ++i)
    {
        event c = events_v[i];
        int cnt = 0; // Counter to indicate how many 
        //rectangles are currently overlapping
        // Delta_x: Distance between current
        // sweep line and previous sweep line
        int delta_x = rects[c.ind][c.type].x - rects[events_v[i - 1].ind]\
        [events_v[i - 1].type].x;
        int begin_y;
        if (delta_x == 0)
        {
            in_set[c.ind] = (c.type == 0);
            continue;
        }
        for (int j = 0; j < e; ++j)
            if (in_set[events_h[j].ind] == 1)
            {
                if (events_h[j].type == 0)
                {
                    if (cnt == 0)
                        begin_y = rects[events_h[j].ind][0].y;
                    ++cnt;
                }
                else
                {
                    --cnt;
                    if (cnt == 0)
                    {
                        int delta_y = (rects[events_h[j].ind][13].y - begin_y);
                        area += delta_x * delta_y;
                    }
                }
            }
        in_set[c.ind] = (c.type == 0); 
    }
    return area;
}