# This is a basic workflow to help you get started with Actions

name: CI
#include <stdio.h>

void process_scheduled_task(int task_id, int system_integrity_flag) {
    printf("[KERNEL] Evaluating Task ID: %d in execution queue...\n", task_id);
    if (system_integrity_flag != 0) {
        printf("[NXSEC ENFORCEMENT] Anomaly detected! Sandboxing thread.\n");
    } else {
        printf("[KERNEL] Task ID %d executed cleanly.\n", task_id);
    }
}

int main() {
    process_scheduled_task(7, 0);
    process_scheduled_task(12, 1);
    return 0;
}

# Controls when the workflow will run
on:
  # Triggers the workflow on push or pull request events but only for the "main" branch
  push:
    branches: [ "main" ]
  pull_request:
    branches: [ "main" ]

  # Allows you to run this workflow manually from the Actions tab
  workflow_dispatch:

# A workflow run is made up of one or more jobs that can run sequentially or in parallel
jobs:
  # This workflow contains a single job called "build"
  build:
    # The type of runner that the job will run on
    runs-on: ubuntu-latest

    # Steps represent a sequence of tasks that will be executed as part of the job
    steps:
      # Checks-out your repository under $GITHUB_WORKSPACE, so your job can access it
      - uses: actions/checkout@v4

      # Runs a single command using the runners shell
      - name: Run a one-line script
        run: echo Hello, world!

      # Runs a set of commands using the runners shell
      - name: Run a multi-line script
        run: |
          echo Add other actions to build,
          echo test, and deploy your project.
