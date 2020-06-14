# For MICRO2020 Rebuttal

Refraser-aware Scheduling tool

## Introduction
* This is a prediction tool to provide the a scheduling table for MICRO2020 paper.
* This tools will generate a table comprise of the priority and number of concurrent process.
* The scheduling table will read by the OS and adaptively change the priority of Deep Learning Application.
* The overall purpose is to guarantee that the Deep Learning Application is not exceeded required time-threshold.
* The priority number will be referenced as nice number in Linux, with the boudary range of [-20:20]. Lower number will be marked as higher priority. ([Ref](https://www.kernel.org/doc/html/latest/scheduler/sched-nice-design.html))


## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes. See deployment for notes on how to deploy the project on a live system.

### Prerequisites

You need to install the softwares:
```
+Centos 5.6
+Python >= 2.7
+GCC/G++ 5.0
```

### Compile
Type in the bash command line:

```
./compile.sh
```

### Running the tests

Run [Refraser-awareScheduling.py](Refraser-awareScheduling.py) script

```
python Refraser-awareScheduling.py
```

### Output
[schedule.csv](schedule.csv)        
* The output data with the X-axis/Y-axis are number of concurrent process/process priority of Deep Learning Application
* **Plase note that:** 
  * The provided numbers are expected finished time of Deep Learning Process
  * The 's'/'t'/'r' characters marked as Safe Zone/Trade-Off Zone/Reloading Zone 

Example:
This is the output [schedule.csv](schedule.csv) with the default priority of concurrent process is 0 and the Deep Learning Process priority are bound in range [-10:9].
```
 ,-10,-9,-8,-7,-6,-5,-4,-3,-2,-1,0,1,2,3,4,5,6,7,8,9,
 0,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,
 1,101,104,107,111,115,121,129,139,148,163,179,207,231,267,310,360,425,510,617,749,
 2,111,117,123,129,139,151,167,187,211,239,271,319,373,439,522,633,759,935,1145,1412,
 3,115,124,130,142,157,172,199,229,265,307,361,427,505,613,736,904,1094,1362,1676,2084,
 4,125,133,145,160,181,204,233,275,323,379,451,539,651,787,954,1178,1432,1790,2212,2756,
 5,135,145,160,180,205,233,270,318,378,448,541,651,791,963,1172,1452,1770,2218,2748,3428,
 6,145,157,178,199,229,262,307,364,436,520,631,760,928,1137,1385,1726,2106,2642,3281,4097,
 7,155,169,193,218,253,292,344,410,494,592,721,872,1068,1312,1602,2001,2444,3070,3816,4769,
 8,165,181,208,237,277,322,381,456,552,664,811,984,1208,1487,1820,2276,2782,3498,4351,5441,
 9,175,193,223,256,301,351,418,502,610,736,901,1096,1348,1662,2038,2551,3120,3926,4886,6113,
 10,185,205,235,275,325,380,455,548,668,808,991,1208,1488,1837,2256,2826,3458,4354,5421,6785,
 11,195,217,250,294,349,409,492,594,726,880,1081,1320,1628,2012,2474,3101,3796,4782,5956,7457,
 12,205,229,265,313,373,438,529,640,784,952,1171,1432,1768,2187,2692,3376,4134,5210,6491,8129,
 13,215,241,280,332,397,467,566,686,842,1024,1261,1544,1908,2362,2910,3651,4472,5638,7026,8801,
 14,225,253,295,351,421,496,603,732,900,1096,1351,1656,2048,2537,3128,3926,4810,6066,7561,9473,
 15,235,265,310,370,445,525,640,778,958,1168,1441,1768,2188,2712,3346,4201,5148,6494,8096,10145,
 16,245,280,325,389,469,554,677,824,1016,1240,1531,1880,2328,2887,3564,4476,5487,6922,8631,10817,
 17,255,292,340,408,493,583,714,870,1074,1312,1621,1992,2468,3062,3782,4751,5826,7350,9166,11489,
 18,265,304,355,427,517,612,751,916,1132,1384,1711,2104,2608,3237,4000,5026,6165,7778,9701,12161,
 19,275,316,370,430,541,641,788,962,1190,1456,1801,2216,2748,3412,4218,5301,6504,8206,10236,12833,


  ,-10,-9,-8,-7,-6,-5,-4,-3,-2,-1,0,1,2,3,4,5,6,7,8,9,
  0,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,
  1,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,t,t,
  2,s,s,s,s,s,s,s,s,s,s,s,s,s,s,t,t,t,t,t,r,
  3,s,s,s,s,s,s,s,s,s,s,s,s,s,t,t,t,t,r,r,r,
  4,s,s,s,s,s,s,s,s,s,s,s,t,t,t,t,t,r,r,r,r,
  5,s,s,s,s,s,s,s,s,s,s,t,t,t,t,t,r,r,r,r,r,
  6,s,s,s,s,s,s,s,s,s,t,t,t,t,t,r,r,r,r,r,r,
  7,s,s,s,s,s,s,s,s,s,t,t,t,t,r,r,r,r,r,r,r,
  8,s,s,s,s,s,s,s,s,t,t,t,t,t,r,r,r,r,r,r,r,
  9,s,s,s,s,s,s,s,s,t,t,t,t,r,r,r,r,r,r,r,r,
  10,s,s,s,s,s,s,s,t,t,t,t,t,r,r,r,r,r,r,r,r,
  11,s,s,s,s,s,s,s,t,t,t,t,r,r,r,r,r,r,r,r,r,
  12,s,s,s,s,s,s,t,t,t,t,t,r,r,r,r,r,r,r,r,r,
  13,s,s,s,s,s,s,t,t,t,t,t,r,r,r,r,r,r,r,r,r,
  14,s,s,s,s,s,s,t,t,t,t,r,r,r,r,r,r,r,r,r,r,
  15,s,s,s,s,s,t,t,t,t,t,r,r,r,r,r,r,r,r,r,r,
  16,s,s,s,s,s,t,t,t,t,t,r,r,r,r,r,r,r,r,r,r,
  17,s,s,s,s,s,t,t,t,t,r,r,r,r,r,r,r,r,r,r,r,
  18,s,s,s,s,t,t,t,t,t,r,r,r,r,r,r,r,r,r,r,r,
  19,s,s,s,s,t,t,t,t,t,r,r,r,r,r,r,r,r,r,r,r,
```

## Running Mode
There are 2 running modes:
* Provide the scheduling table with all the coming process has a same default of priority number. The example is given above.
* Provide the scheduling table with the coming processes have different process priority numbers.

For example:
  * We find the safe zone of deep learning process by input the 10 concurrent process with their priority is 1,2,3,-4,-5,-6,-7,-8,0,1 as described in [process_prio_map.dat](process_prio_map.dat)
  ```
  10
  1,2,3,-4,-5,-6,-7,-8,0,1
  ```
  * We run the "Refraser-awareScheduling.py" with the option **enable_file_prio_map=1**
  ```
  python Refraser-awareScheduling.py
  ```
  * The output [schedule.csv](schedule.csv):
  ```
   ,-10,-9,-8,-7,-6,-5,-4,-3,-2,-1,0,1,2,3,4,5,6,7,8,9,
    0,317,375,446,535,647,786,960,1182,1464,1796,2219,2756,3428,4250,5260,6620,8133,10271,12817,16070,
    
    
   ,-10,-9,-8,-7,-6,-5,-4,-3,-2,-1,0,1,2,3,4,5,6,7,8,9,
   0,s,s,s,t,t,t,t,t,r,r,r,r,r,r,r,r,r,r,r,r,
  ```
  * It means that the Deep Learning Application can work in the Safe zone with its process priority are -10 and -9. The priority from -8 to -4 is trade-off zone.

## How to change the parameters

Modify "Refraser-awareScheduling.py" file

### Usage of key parameters 
* *num_core= < number 0-7 >* :          **Set the CPU configuations:**
  * 0: UNIPROCESSOR
  * 1: DUAL_CPU
  * 2: DUAL_CPU_MC
  * 3: QUAD_CPU
  * 4: QUAD_CPU_MC
  * 5: QUAD_CPU_DUAL_SOCKET
  * 6: QUAD_CPU_QUAD_SOCKET
  * 7: HEX_CPU_DUAL_SOCKET_SMT

* *running_time= < time in ns >* :      **Set the Deep Learning Application running time.**

* *safe_zone= < time in ns >* :        **Set the upperbound constraint of Safe Zone**

* *tradeoff_zone= < time in ns >* :     **Set the upperbound constraint of Trade-Off Zone**

* *default_concurrent_task_prio= < priority number >* :        **Set default priority number of all concurrent tasks if enable_file_prio_map is un-set**

* *enable_file_prio_map= < 0/1 >* :    **Set/un-Set the priority process from file [process_prio_map.dat](process_prio_map.dat)**
  * [process_prio_map.dat](process_prio_map.dat) format is comprised 2 lines:
    - Number of concurrent task
    - Priority number of each task
            


## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details

