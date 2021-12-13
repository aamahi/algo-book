#include<cstdio>


double tri_area(double x1,double y1,double x2, double y2, double x3,double y3);
int main()
{
    float x1,y1,x2,y2,x3, y3,ans;

    scanf("%f %f %f %f %f %f",&x1,&y1,&x2,&y2,&x3,&y3);
    ans=tri_area(x1,y1,x2,y2,x3,y3);
    printf("\n%llf",ans);

    return 0;
}
double tri_area(double x1,double y1,double x2, double y2, double x3,double y3)
{

    return (x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2))/2;
}


