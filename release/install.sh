#!/bin/bash
echo 'Downloading the tar ball'
curl -O https://raw.githubusercontent.com/RayofLightz/powerpend/master/release/powerpend.tar.gz

echo 'Extracting the tar ball'
tar xfvz powerpend.tar.gz

echo 'Setting executable permissions'
chmod +x powerpend

echo 'creating /opt/powerpend/'
sudo mkdir /opt/powerpend/
sudo mv powerpend /opt/powerpend/

echo 'creating symlink to /usr/local/bin'
sudo ln -s /opt/powerpend/powerpend /usr/local/bin/powerpend

