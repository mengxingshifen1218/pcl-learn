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
	PointCloud<PointXYZRGB>::Ptr cloud(new PointCloud<PointXYZRGB>);   //创建点云指针

	if (io::loadPCDFile("/home/djq/catkin_ws/src/learn-pointcloud/src/data/01.pcd", *cloud) == -1)    //读取pcd文件
	{ 
		cerr << "can't read file pcl.pcd" << endl;
		return -1;
	}

	boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer(new pcl::visualization::PCLVisualizer("3D Viewer"));  //创建视窗对象，并给标题栏定义一个名称"3D Viewer"，我们将它定义为boost::shared_ptr智能共享指针，这样可以保证该指针在整个程序全局使用，而不引起内存错误，通常情况下，用户不需要这样做。名称为“3D Viewer”

	pcl::visualization::PointCloudColorHandlerRGBField<pcl::PointXYZRGB> rgb(cloud); //创建一个颜色处理对象PointCloudColorHandlerRGB，PCLVisualizer类利用这样的对象显示自定义颜色数据，在这个示例中，PointCloudColorHandlerRGB对象得到每个点云的RGB颜色字段

	viewer->addPointCloud<pcl::PointXYZRGB>(cloud, "sample cloud");  //这是最重要的一行，我们将点云添加到视窗对象中，并定义一个唯一的字符串作为ID号，利用此字符串保证在其他成员方法中也能标识引用该点云，多次调用addPointCloud()，可以实现多个点云的添加，每调用一次就创建一个新的ID号，如果想更新一个已经显示的点云，用户必须先调用removePointCloud()，并提供需要更新的点云的ID号。（注：PCL 的1.1及以上版本提供一个新的API，updatePointCloud()，通过该接口，不必手动调用removePointCloud()，就可实现点云的更新）。
	viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 3, "sample cloud"); // 用于改变显示点云的尺寸。用户可以利用该方法控制点云在视窗中的显示方式。
    viewer->setBackgroundColor(0.1, 0.1, 0.1); //设置视窗的颜色

	while (!viewer->wasStopped())  //执行一个while循环，每次调用spinOnce都给视窗处理事件的时间，这样允许鼠标键盘等交互操作，此外还有一种spin的重载方法，它只需调用一次。
	{
		viewer->spinOnce(100);
		boost::this_thread::sleep(boost::posix_time::microseconds(100000));
	}

	return 0;
}
