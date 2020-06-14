/* LinSched -- The Linux Scheduler Simulator
 * Copyright (C) 2008  John M. Calandrino
 * E-mail: jmc@cs.unc.edu
 *
 * Example scheduling simulation. Tasks are created and then the simulation
 * is run for some number of ticks.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program (see COPYING); if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */
#include "linsched.h"
#include <strings.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define LINSCHED_TICKS 60000

int linsched_test_main(int argc, char **argv)
{
  int i = 0;
  int conf = 0;
  int priority = 0;
  int run_time = 0;
  int io_time = 0;
  int num_task = 0;
  int default_prio_of_concurrent_task = 0;
  int parser_prio_from_file = 0;
  int ret = 0;
  int *prioArr;
  FILE *prioFile;
 
  if (argc < 8) {
    printf("Command: ./linsched conf priority run_time io_time num_task default_prio_of_concurrent_task parser_prio_from_file\n");
    printf("Example: ./linsched 0 0 100 10 10 0 0 0\n");
    return 0;
  }

  conf      = atoi(argv[1]);
  priority  = atoi(argv[2]);
  //run_time  = atof(argv[3]);
  //io_time   = atof(argv[4]);
  run_time  = atoi(argv[3]);
  io_time   = atoi(argv[4]);
  num_task  = atoi(argv[5]);
  default_prio_of_concurrent_task  = atoi(argv[6]);
  parser_prio_from_file  = atoi(argv[7]);

  //printf("Debug arg %d conf %d priority %d run_time %d io_time %d max_wait %d num_task %d\n", argc, conf, priority, run_time, io_time, max_wait, num_task);

	/* Initialize linsched. */
  struct linsched_topology topo = TOPO_UNIPROCESSOR;
  //struct linsched_topology topo = TOPO_QUAD_CPU;
  //switch (conf) {
  //  case 0: topo = TOPO_UNIPROCESSOR; break;
  //  case 1: topo = TOPO_DUAL_CPU; break;
  //  case 2: topo = TOPO_DUAL_CPU_MC; break;
  //  case 3: topo = TOPO_QUAD_CPU; break;
  //  case 4: topo = TOPO_QUAD_CPU_MC; break;
  //  case 5: topo = TOPO_QUAD_CPU_DUAL_SOCKET; break;
  //  case 6: topo = TOPO_QUAD_CPU_QUAD_SOCKET; break;
  //  case 7: topo = TOPO_HEX_CPU_DUAL_SOCKET_SMT; break;
  //  default: topo = TOPO_UNIPROCESSOR; break;
  //}
	linsched_init(&topo);

	/* Create some tasks with "callbacks" that should be called
	 * every scheduling decision.
	 */
  struct task_data *t = linsched_create_deep_task_sleep_run(io_time, run_time);
  struct sleep_run_task *d = t->data;
	struct task_struct *p = linsched_create_normal_task(t, priority);

  if (parser_prio_from_file) {
    //override number of task
    prioFile = fopen("process_prio_map.dat", "r");
    fscanf(prioFile, "%d\n", &num_task);
    if (num_task <= 0) return 1;
    else
      prioArr = (int*) malloc(sizeof(int)*num_task);

    for (i = 0; i < num_task; i++) {
      fscanf(prioFile, "%d,", &prioArr[i]);
      //printf("%d,", prioArr[i]);
    }

    for (i = 0; i < num_task; i++) {
	    linsched_create_normal_task(linsched_create_sleep_run(10, 9000), prioArr[i]);
    }
  }
  else {
    for (i = 0; i < num_task; i++) {
	    linsched_create_normal_task(linsched_create_sleep_run(10, 9000), default_prio_of_concurrent_task);
    }
  }

	/* Run simulation until deep task are gone */
  //while ((p->se.sum_exec_runtime < run_time*NSEC_PER_MSEC) && (d->wait < max_wait*NSEC_PER_MSEC)) {
  while ((p->se.sum_exec_runtime < run_time*NSEC_PER_MSEC)) {
	  linsched_run_sim(1);
    //printf("Deep task delay %llu \n", d->wait);
  }

  //u64 total_all_exectuting_time = linsched_print_task_stats();

  u64 total_delay = p->sched_info.run_delay;
  u64 total_invoked_time = p->sched_info.pcount;
  u64 total_exectuting_time = p->se.sum_exec_runtime;
  u64 total_all_exectuting_time = total_exectuting_time + total_delay;

  //printf("Average waiting time: %llu \n", total_delay/total_invoked_time);
  //printf("Average running time: %llu \n", total_exectuting_time/total_invoked_time);
  //printf("Execututing time: %llu \n", total_exectuting_time/NSEC_PER_MSEC);
  //printf("Total running time: %llu \n", total_all_exectuting_time/NSEC_PER_MSEC);
  ret = total_all_exectuting_time/NSEC_PER_MSEC;
  printf("%u", ret);
  if (parser_prio_from_file) {
    free(prioArr);
    fclose(prioFile);
  }
  return 0;
  //if (total_all_exectuting_time > max_wait*NSEC_PER_MSEC) {
  //  //printf("Executing more than waiting %llu - %llu\n", total_all_exectuting_time, max_wait*NSEC_PER_MSEC);
  //  return 1;
  //}
  //else if (d->wait >= max_wait*NSEC_PER_MSEC) {
  //  //printf("Wait more than normal %llu - %llu\n", d->wait , max_wait*NSEC_PER_MSEC);
  //  return 2;
  //}
  //else {
  //  //printf("Normal \n");
  //  return 0;
  //}
}
