#include <pcl/io/pcd_io.h>
#include <pcl/common/impl/io.hpp>
#include <pcl/point_types.h>
#include <pcl/point_cloud.h>

int main(int argc, char **argv)
{
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);
	pcl::io::loadPCDFile<pcl::PointXYZ>("/home/djq/catkin_ws/src/learn-pointcloud/src/data/01.pcd", *cloud);
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloudOut(new pcl::PointCloud<pcl::PointXYZ>);
	std::vector<int > indexs = { 1, 2, 5 };
	pcl::copyPointCloud(*cloud, indexs, *cloudOut);
    std::cout << "size: " << cloud->points.size() << std::endl;
    std::cout << "size: " << cloudOut->points.size() << std::endl;
}
