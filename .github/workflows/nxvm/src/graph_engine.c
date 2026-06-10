# This is a basic workflow to help you get started with Actions

name: CI
#include <stdio.h>
#include <string.h>

typedef struct {
    char key_string[64];
    int numeric_value;
} metadata_property_t;

typedef struct graph_node {
    int node_id;
    metadata_property_t properties[8];
} graph_node_t;

void assign_node_string_meta(graph_node_t* target, const char* val) {
    strncpy(target->properties[0].key_string, val, 63);
    target->properties[0].key_string[63] = '\0';
    printf("[NXVM] Allocated nested string metadata property: '%s'\n", target->properties[0].key_string);
}

int main() {
    graph_node_t sample_vertex;
    sample_vertex.node_id = 101;
    assign_node_string_meta(&sample_vertex, "Core_Edge_Router_Alpha");
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
