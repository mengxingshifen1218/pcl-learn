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
#include <iostream>


int main(int argc, char** argv)
{
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_filtered(new pcl::PointCloud<pcl::PointXYZ>);
	
	// pcl::io::loadPLYFile("01.ply", *cloud);

    ````pcl::io::loadPCDFile("/home/djq/catkin_ws/src/learn-pointcloud/src/data/01.pcd", *cloud);

	std::cerr << "Cloud before filtering: " << std::endl;
	std::cerr << *cloud << std::endl;

	pcl::visualization::PCLVisualizer viewer("滤波");
	int v1(0);
	int v2(1);
	viewer.createViewPort(0.0, 0.0, 0.5, 1, v1);
	viewer.setBackgroundColor(0, 0, 0, v1);

	viewer.createViewPort(0.5, 0.0, 1, 1, v2);
	viewer.setBackgroundColor(0.5, 0.5, 0.5, v2);

	pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> cloud_out_green(cloud, 20, 180, 20);//绿色点云 
	viewer.addPointCloud(cloud, cloud_out_green, "cloud_out1", v1);

	pcl::PassThrough<pcl::PointXYZ> pass;  //设置滤波器对象
	pass.setInputCloud(cloud);  //设置输入点云
	pass.setFilterFieldName("y");  //设置过滤是所需要的点云类型的y字段
	pass.setFilterLimits(0.4, 0.9);  //设置在过滤字段上的范围
	pass.setFilterFieldName("x");
	pass.setFilterLimits(-0.8, 0.65);
	//pass.setFilterLimitsNegative (true);  //设置保留范围内的还是过滤范围内的
	pass.filter(*cloud_filtered);  //执行滤波，保存过滤结果在cloud_filtered
	std::cerr << "Cloud after filtering: " << std::endl;
	std::cerr << *cloud_filtered << std::endl;
	/*pcl::PCDWriter writer;*/
	//writer.write<pcl::PointXYZ> ("table_scene_lms400_inliers.pcd", *cloud_filtered, false);
	//sor.setNegative (true);
	//sor.filter (*cloud_filtered);
	//writer.write<pcl::PointXYZ> ("table_scene_lms400_outliers.pcd", *cloud_filtered, false);
	pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> cloud_out_orage(cloud_filtered, 250, 128, 10);   //显示橘色点云
	viewer.addPointCloud(cloud_filtered, cloud_out_orage, "cloud_out2", v2);
	//viewer.setSize(960, 780);
	while (!viewer.wasStopped())
	{
		viewer.spinOnce();
	}
	return 0;
}
