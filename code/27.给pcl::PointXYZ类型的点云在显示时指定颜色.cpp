#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/point_cloud.h>
#include <pcl/visualization/pcl_visualizer.h>

int main(int argc, char **argv)
{
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);
    pcl::io::loadPCDFile<pcl::PointXYZ>("/home/djq/catkin_ws/src/learn-pointcloud/src/data/01.pcd", *cloud);
    // pcl::io::loadPCDFile("/home/djq/catkin_ws/src/learn-pointcloud/src/data/01.pcd", *cloud);
    
    pcl::visualization::PCLVisualizer viewer("pointcloud viewer");
    pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> sig(cloud, 0, 234, 0);
    viewer.addPointCloud(cloud, sig, "cloud");
    while (!viewer.wasStopped())
    {
        viewer.spinOnce();
    }
}
