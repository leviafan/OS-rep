#!/bin/bash
gcc trashmaker.c -o tmake                                                 
time ./tmake &                                                                         
PID=`ps -a | grep "tmake" | awk '{print $1}'`              
k=1;    
while [  -z `ps -a | grep "tmake" | awk '{print $1}'` ]; do                                        
 taskset -p $k $PID > /dev/null                                          
 k=$(($k^1));                                                                            
done                                                                                                    
time ./tmake                                                                               
rm tmake                                                                                   
