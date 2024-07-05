# A Kernel Seedling
add a file called count in proc directory which count the current number of process.

## Building
```shell
make  // to build module
sudo insmod proc_count.ko // to insert module to kernel (.ko = kernel object)
```

## Running

```shell
cat /proc/count
```
the single interger that shows the number of current running process.

## Cleaning Up

to remove module.

```shell
sudo rmmod proc_count
```

## Testing
```python
python -m unittest
```
if test passes

.....
---------------------------------------
Ran 3 tests in 14.475s

OK

if test failed

F..
=========================
the content of error

-----------------------------
Ran 3 tests in some time

FAILED (failures=1) 

Report which kernel release version you tested your module on
(hint: use `uname`, check for options with `man uname`).
It should match release numbers as seen on https://www.kernel.org/.

```shell
uname -r -s -v
```
Linux 5.14.8-arch1-1 

# cs111
# cs111
