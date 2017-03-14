# VLC工程编译

```bash
while test -n "$1"
do
	case "$1" in
	        --build=*)
	                BUILD="${1#--build=}"
	                ;;
	        --help|-h)
	                usage
	                exit 0
	                ;;
	        --host=*)
	                HOST="${1#--host=}"
#
```