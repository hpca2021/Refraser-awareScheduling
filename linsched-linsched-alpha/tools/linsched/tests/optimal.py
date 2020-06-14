import os;

num_core = 0;
running_time = 66.1;
io_time = 0;
waiting_time0 = 102.475;
waiting_time1 = 112.608;
waiting_time2 = 1309.309;
waiting_time3 = 1490;
waiting_time4 = 3796;
waiting_time5 = 4205;
found = 9999


def binary_search(run_cmd, last):
  first = 0;
  while (first <= last):
    mid = (first+last)/2
    running_cmd = run_cmd+" "+str(mid)
    ret = os.system(running_cmd)
    if not ret:
      first = mid+1
    else:
      if last == 1:
        return 1
      last = mid-1
  return last

#for p in range(-19,21):
for p in range(-3,1):
  run_cmd = "./linsched "+" "+str(num_core)+" "+str(p)+" "+str(running_time)+" "+str(io_time)+" "+str(waiting_time0);
  found = binary_search(run_cmd, found)
  print "Priority "+str(p)+" Max process "+str(found);

found = 9999
for p in range(-3,1):
  run_cmd = "./linsched "+" "+str(num_core)+" "+str(p)+" "+str(running_time)+" "+str(io_time)+" "+str(waiting_time1);
  found = binary_search(run_cmd, found)
  print "Priority "+str(p)+" Max process "+str(found);

found = 9999
for p in range(-3,1):
  run_cmd = "./linsched "+" "+str(num_core)+" "+str(p)+" "+str(running_time)+" "+str(io_time)+" "+str(waiting_time2);
  found = binary_search(run_cmd, found)
  print "Priority "+str(p)+" Max process "+str(found);

found = 9999
for p in range(-3,1):
  run_cmd = "./linsched "+" "+str(num_core)+" "+str(p)+" "+str(running_time)+" "+str(io_time)+" "+str(waiting_time3);
  found = binary_search(run_cmd, found)
  print "Priority "+str(p)+" Max process "+str(found);

found = 9999
for p in range(-3,1):
  run_cmd = "./linsched "+" "+str(num_core)+" "+str(p)+" "+str(running_time)+" "+str(io_time)+" "+str(waiting_time4);
  found = binary_search(run_cmd, found)
  print "Priority "+str(p)+" Max process "+str(found);

found = 9999
for p in range(-3,1):
  run_cmd = "./linsched "+" "+str(num_core)+" "+str(p)+" "+str(running_time)+" "+str(io_time)+" "+str(waiting_time5);
  found = binary_search(run_cmd, found)
  print "Priority "+str(p)+" Max process "+str(found);

