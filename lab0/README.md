# A Kernel Seedling
add a file called count in proc directory which count the current number of process.

## Building
insert module to kernel

.ko file is kernel object file.
```shell
sudo insmod proc_count.ko
```

## Running

```shell
sudo insmod proc_count.ko
```
TODO: results?

## Cleaning Up
```shell
TODO: cmd for cleaning the built binary
```

## Testing
```python
python -m unittest
```
TODO: results?

Report which kernel release version you tested your module on
(hint: use `uname`, check for options with `man uname`).
It should match release numbers as seen on https://www.kernel.org/.

```shell
uname -r -s -v
```
TODO: kernel ver?# cs111
# cs111
# cs111
