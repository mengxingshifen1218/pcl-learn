#include <iostream>
#include <pcl/point_types.h>
#include <pcl/point_cloud.h>
#include <pcl/visualization/pcl_visualizer.h>
 
int main(int argc, char** argv)
{
    //显示类
    pcl::visualization::PCLVisualizer viewer("Cloud Viewer");
 
    //添加坐标系
    viewer.addCoordinateSystem();  
 
    //让可视化视窗停住，否则一闪而过。
    while (!viewer.wasStopped())
    {  
        viewer.spinOnce();
    }
 
    return (0);
}
