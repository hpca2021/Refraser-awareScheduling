import sys;
import os;
import subprocess;
import numpy as np
import timeit

#start = timeit.default_timer()

#Time unit is miliseconds
num_core = 0;
running_time = 91;
safe_zone = 512;
tradeoff_zone = 1293;
io_time = 0;
default_cocurrent_task_prio = 0;
enable_file_prio_map = 0;

min_prio = -10
max_prio = 10
max_process = 20

range_prio = max_prio - min_prio

#if len(sys.argv) < 2:
#  print("Please input more than 3")
#  sys.exit(0)



f = open("schedule.csv", "w");

#print(arr)
#print(arr2)
if enable_file_prio_map:
  os.system("cp ./process_prio_map.dat ./linsched-linsched-alpha/tools/linsched/tests/");

  rows, cols = (1, range_prio)
  arr = np.array([[9999]*cols]*rows)

  #s is safe zone | t is trade-off | r is reloading zone
  #default is reloading state
  arr2 = np.array([['r']*cols]*rows)

  for prio in range(min_prio,max_prio):
    run_cmd = "./linsched-linsched-alpha/tools/linsched/tests/linsched "+" "+str(num_core)+" "+str(prio)+" "+str(running_time)+" "+str(io_time)+" "+str("0")+" "+str(default_cocurrent_task_prio)+" 1";
    ########################
    # Call the C-function, which the return
    # the expected finish time of Deep Learning Process
    ########################
    ret = int(subprocess.Popen(run_cmd, shell=True, stdout=subprocess.PIPE).stdout.read());
    #print run_cmd+" Priority "+str(prio)+" Num of Process "+str(proc)+" Total exectuting time "+str(ret);
    arr[0][prio-min_prio] = ret;
    if (ret < safe_zone):
      arr2[0][prio-min_prio] = 's';
    elif (ret < tradeoff_zone):
      arr2[0][prio-min_prio] = 't';
    else:
      arr2[0][prio-min_prio] = 'r';
else:
  rows, cols = (max_process, range_prio)
  arr = np.array([[9999]*cols]*rows)

  #s is safe zone | t is trade-off | r is reloading zone
  #default is reloading state
  arr2 = np.array([['r']*cols]*rows)

  for proc in range (0,max_process):
    for prio in range(min_prio,max_prio):
      run_cmd = "./linsched-linsched-alpha/tools/linsched/tests/linsched "+" "+str(num_core)+" "+str(prio)+" "+str(running_time)+" "+str(io_time)+" "+str(proc)+" "+str(default_cocurrent_task_prio)+" 0";
    ########################
    # Call the C-function, which the return
    # the expected finish time of Deep Learning Process
    ########################
      ret = int(subprocess.Popen(run_cmd, shell=True, stdout=subprocess.PIPE).stdout.read());
      #print run_cmd+" Priority "+str(prio)+" Num of Process "+str(proc)+" Total exectuting time "+str(ret);
      arr[proc][prio-min_prio] = ret;
      if (ret < safe_zone):
        arr2[proc][prio-min_prio] = 's';
      elif (ret < tradeoff_zone):
        arr2[proc][prio-min_prio] = 't';
      else:
        arr2[proc][prio-min_prio] = 'r';

i = 0
f.write(str(' ')+",")
for prio in range(min_prio,max_prio):
  f.write(str(prio)+",")
f.write("\n")
for col in arr:
  f.write(str(i)+",")
  for el in col:
    f.write(str(el)+",")
  f.write("\n")
  i = i +1

f.write("\n")
f.write("\n")
i = 0
f.write(str(' ')+",")
for prio in range(min_prio,max_prio):
  f.write(str(prio)+",")
f.write("\n")
for col in arr2:
  f.write(str(i)+",")
  for el in col:
    f.write(str(el)+",")
  f.write("\n")
  i = i +1

print(arr)
print(arr2)

f.close();

#stop = timeit.default_timer()

#print('Time: ', stop - start)
