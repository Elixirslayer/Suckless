#!/bin/sh

disk_free=$(df -h / | awk 'NR==2 {print $4}')
echo "${disk_free}"

