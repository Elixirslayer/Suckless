#!/bin/bash

cpu_temp=$(sensors | awk '/^Package/ {print $4}' | tr -d '+°C')
cpu_usage=$(top -bn1 | grep '%Cpu' | sed 's/,/./g' | awk '{print $2 + $4}')
echo "${cpu_usage}%/${cpu_temp}°C"

