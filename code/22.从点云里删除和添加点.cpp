#include <pcl/io/pcd_io.h>
#include <pcl/common/impl/io.hpp>
#include <pcl/point_types.h>
#include <pcl/point_cloud.h>
int main(int argc, char **argv)
{
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);
	pcl::io::loadPCDFile<pcl::PointXYZ>("/home/djq/catkin_ws/src/learn-pointcloud/src/data/01.pcd", *cloud);
	pcl::PointCloud<pcl::PointXYZ>::iterator index = cloud->begin();
	cloud->erase(index);//删除第一个
	index = cloud->begin() + 5;
	cloud->erase(cloud->begin());//删除第5个
	pcl::PointXYZ point = { 1, 1, 1 };
	//在索引号为5的位置1上插入一点，原来的点后移一位
	cloud->insert(cloud->begin() + 5, point);
	cloud->push_back(point);//从点云最后面插入一点
	std::cout << cloud->points[5].x;//输出1
}

