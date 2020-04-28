#include <pcl/io/ply_io.h>
#include <pcl/io/pcd_io.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/filters/voxel_grid.h>
#include <iostream>
#include <vector>
  
  
int main(int argc, char **argv) 
{
    pcl::PointCloud<pcl::PointXYZRGBA>::Ptr cloudadd(new pcl::PointCloud<pcl::PointXYZRGBA>);
    pcl::PointCloud<pcl::PointXYZRGBA>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZRGBA>);
    pcl::io::loadPLYFile("000.ply", *cloud);
    pcl::PointCloud<pcl::PointXYZRGBA>::Ptr cloud1(new pcl::PointCloud<pcl::PointXYZRGBA>);
    pcl::io::loadPLYFile("001.ply", *cloud1);
     
    *cloudadd = *cloud + *cloud1;
    pcl::io::savePLYFileBinary("test_pcd.ply", *cloudadd);
    
    cloud->clear();
    pcl::io::loadPLYFile("002.ply", *cloud);
    *cloudadd = *cloudadd + *cloud;
  
    cloud->clear();
    pcl::io::loadPLYFile("003.ply", *cloud);
    *cloudadd = *cloudadd + *cloud;
  
    cloud->clear();
    pcl::io::loadPLYFile("004.ply", *cloud);
    *cloudadd = *cloudadd + *cloud;
  
    cloud->clear();
    pcl::io::loadPLYFile("005.ply", *cloud);
    *cloudadd = *cloudadd + *cloud;
  
    cloud->clear();
    pcl::io::loadPLYFile("006.ply", *cloud);
    *cloudadd = *cloudadd + *cloud;
  
    cloud->clear();
    pcl::io::loadPLYFile("007.ply", *cloud);
    *cloudadd = *cloudadd + *cloud;
  
    pcl::io::savePLYFileBinary("last.ply", *cloudadd);
  
    pcl::visualization::CloudViewer viewer("Cloud Viewer");
  
    viewer.showCloud(cloud);
  
    while (!viewer.wasStopped())
    {
        user_data++;
    }

    return 0;
}
