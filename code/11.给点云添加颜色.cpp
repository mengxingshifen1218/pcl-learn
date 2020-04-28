#include <pcl/common/common_headers.h>
#include <pcl/io/pcd_io.h>
#include <pcl/io/io.h>
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
using namespace std;
using namespace pcl;
using namespace io;

int main() 
{
	PointCloud<PointXYZ>::Ptr cloud(new PointCloud<PointXYZ>);

	if (io::loadPCDFile("/home/djq/catkin_ws/src/learn-pointcloud/src/data/01.pcd", *cloud) == -1) 
	{ 
		cerr << "can't read file ping2.pcd" << endl;
		return -1;
	}

	boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer(new pcl::visualization::PCLVisualizer("3D Viewer"));

	pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> single_color(cloud, 0, 255, 0); // 这里我们需要创建一个自定义颜色处理器PointCloudColorHandlerCustom对象，并设置颜色为纯绿色。

	viewer->addPointCloud<pcl::PointXYZ>(cloud, single_color, "sample cloud");  //当我们添加点云的时候，我们可以指定添加到视窗中点云的PointCloudColorHandlerRGB着色处理对象。
	//viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_COLOR, 0, 0, 1, "sample cloud");// 也可以
	while (!viewer->wasStopped())
	{
		viewer->spinOnce(100);
		boost::this_thread::sleep(boost::posix_time::microseconds(100000));
	}
	return 0;
}
