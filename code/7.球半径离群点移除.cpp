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

int main(int argc, char** argv)
{

	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_filtered(new pcl::PointCloud<pcl::PointXYZ>);
	// 填入点云数据
	// pcl::io::loadPLYFile("01.ply", *cloud);
    pcl::io::loadPCDFile("/home/djq/catkin_ws/src/learn-pointcloud/src/data/01.pcd", *cloud);
	std::cerr << "Cloud before filtering:" << std::endl;
	std::cerr << *cloud << std::endl;

	pcl::visualization::PCLVisualizer viewer("滤波");
	int v1(0);
	int v2(1);
	viewer.createViewPort(0.0, 0.0, 0.5, 1, v1);
	viewer.setBackgroundColor(0, 0, 0, v1);
	viewer.createViewPort(0.5, 0.0, 1, 1, v2);
	viewer.setBackgroundColor(0.5, 0.5, 0.5, v2);

	pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> cloud_out_green(cloud, 20, 180, 20);
	viewer.addPointCloud(cloud, cloud_out_green, "cloud_out1", v1);

	//2.半径滤波
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_filter(new pcl::PointCloud<pcl::PointXYZ>);
	pcl::RadiusOutlierRemoval<pcl::PointXYZ> sor;//创建滤波器对象
	sor.setInputCloud(cloud);//设置待滤波的点云
	sor.setRadiusSearch(0.02);// 设置搜索半径
	sor.setMinNeighborsInRadius(15);// 设置一个内点最少的邻居数目
	sor.setNegative(false);
	sor.filter(*cloud_filtered); // 滤波结果存储到cloud_filtered

	std::cerr << "Cloud after filtering:" << std::endl;
	std::cerr << *cloud_filtered << std::endl;

	pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> cloud_out_orage(cloud_filtered, 250, 128, 10);
	viewer.addPointCloud(cloud_filtered, cloud_out_orage, "cloud_out2", v2);
	//viewer.setSize(960, 780);
	while (!viewer.wasStopped())
	{
		viewer.spinOnce();
	}
	return 0;
}
