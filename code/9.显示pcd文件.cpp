#include <pcl/common/common_headers.h>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>    
#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/visualization/cloud_viewer.h>
#include <pcl/console/parse.h>
#include <pcl/point_cloud.h>        //点类型定义头文件
#include <pcl/kdtree/kdtree_flann.h> //kdtree类定义头文件
#include <pcl/point_cloud.h>
#include <pcl/octree/octree.h>
#include <pcl/filters/statistical_outlier_removal.h>
#include <pcl/filters/passthrough.h>
#include <pcl/filters/voxel_grid.h>
#include <pcl/filters/statistical_outlier_removal.h>
#include <pcl/filters/radius_outlier_removal.h>  //滤波相关
#include <pcl/ModelCoefficients.h>             //模型系数头文件
#include <pcl/filters/project_inliers.h>          //投影滤波类头文件
#include <iostream>


// pcl::io::loadPCDFile("/home/djq/catkin_ws/src/learn-pointcloud/src/data/01.pcd", *cloud);

int main(int argc, char** argv)
{
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>); // 创建点云（指针）

	if (pcl::io::loadPCDFile<pcl::PointXYZ>("/home/djq/catkin_ws/src/learn-pointcloud/src/data/01.pcd", *cloud) == -1) //* 读入PCD格式的文件，如果文件不存在，返回-1
	{
		PCL_ERROR("Couldn't read file ping2.pcd \n"); //文件不存在时，返回错误，终止程序。
		return (-1);
	}
	pcl::visualization::CloudViewer viewer("Simple Cloud Viewer");//直接创造一个显示窗口
	viewer.showCloud(cloud);//在这个窗口显示点云
	while (!viewer.wasStopped())
	{
	}
	return (0);
}
