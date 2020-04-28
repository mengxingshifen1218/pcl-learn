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

        pcl::visualization::PointCloudColorHandlerGenericField<pcl::PointXYZ> fildColor(cloud, "z"); // 按照z字段进行渲染
        
        viewer->addPointCloud<pcl::PointXYZ>(cloud, fildColor, "sample cloud");
        viewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 3, "sample cloud"); // 设置点云大小

        while (!viewer->wasStopped())
        {
            viewer->spinOnce(100);
            boost::this_thread::sleep(boost::posix_time::microseconds(100000));
        }

    return 0;

}

