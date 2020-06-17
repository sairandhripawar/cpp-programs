#include <iostream> 
using namespace std; 
#define INF 10000 
struct Pt
{ 
    int x,y; 
    
}; 

bool onSeg(Pt p, Pt q, Pt r) 
{ 
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) && 
            q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y)) 
        return true; 
    return false; 
} 


double otn(Pt p, Pt q, Pt r) 
{ 
    double val = (q.y - p.y) * (r.x - q.x) - 
              (q.x - p.x) * (r.y - q.y); 
  
    if (val == 0) return 0;  // colinear 
    return (val > 0)? 1: 2; // clock or anticlock wise 
} 
  

bool doIntersect(Pt p1, Pt q1, Pt p2, Pt q2) 
{ 

    double o1 = otn(p1, q1, p2); 
    double o2 = otn(p1, q1, q2); 
    double o3 = otn(p2, q2, p1); 
    double o4 = otn(p2, q2, q1); 
  
    
    if (o1 != o2 && o3 != o4) 
        return true; 
  
 
   
    if (o1 == 0 && onSeg(p1, p2, q1)) return true; 
  
   
    if (o2 == 0 && onSeg(p1, q2, q1)) return true; 
  
   
    if (o3 == 0 && onSeg(p2, p1, q2)) return true; 
  
    
    if (o4 == 0 && onSeg(p2, q1, q2)) return true; 
  
    return false; 
} 
  

bool isInside(Pt polygon[], int n, Pt p) 
{ 
   
    if (n < 3)  return false; 
  
     
    Pt extreme = {INF, p.y}; 
  
   
    int count = 0, i = 0; 
    do
    { 
        int next = (i+1)%n; 

        if (doIntersect(polygon[i], polygon[next], p, extreme)) 
        { 
  
            if (otn(polygon[i], p, polygon[next]) == 0) 
               return onSeg(polygon[i], p, polygon[next]); 
  
            count++; 
        } 
        i = next; 
    } while (i != 0); 
  

    return count&1;  
} 
int main()
{ 
    Pt polygon1[] = {{1, 0}, {8, 3}, {8, 8}, {1, 5}}; 
    int n = sizeof(polygon1)/sizeof(polygon1[0]); 
    Pt p = {3, 5}; 
    isInside(polygon1, n, p)? cout << "TRUE \n": cout << "FALSE \n"; 
  
    Pt polygon2[] = {{-3,2}, {-2,-0.8}, {0,1.2} ,{2.2,0}, {2,4.5}}; 
    p = {0,0}; 
   	n = sizeof(polygon2)/sizeof(polygon2[0]); 
    isInside(polygon2, n, p)? cout << "FALSE \n": cout << "FALSE \n"; 
      return 0; 
}
  


