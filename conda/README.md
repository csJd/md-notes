# MY CONDA CHEAT SHEET

## Conda basics
[See Official gs here](https://conda.io/docs/user-guide/getting-started.html)

```sh
conda info                  # Verify conda is installed, check version number
conda update conda          # Update conda to the current version
conda search PACKAGENAME    # Use conda to search for a package
conda install PACKAGENAME   # Install a package included in Anaconda
conda update PACKAGENAME    # Update any installed program
spyder                      # Run a package after install, example Spyder*
conda install --help        # COMMANDNAME --help
```


## Using environments
```sh
conda create --name py2 python=2.7      # Create a new environment named py2, install Python 2.7
activate py2                            # Activate the new environment to use it in WIN
source activate py2                     # Activate the new environment to use it in Unix
conda env list                          # Get a list of all my environments
conda create --clone py2 --name py2_0   # Make exact copy of an environment
```
