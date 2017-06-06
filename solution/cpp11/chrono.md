# c++ 11 chrono

## 计算格里高历的duration（秒， 毫秒）

```
ptime epoch(boost::gregorian::date(1970,1,1));
time_duration::sec_type x
```
[http://blog.csdn.net/huang_xw/article/details/8245049](boost time_duration计算epoch)
[https://stackoverflow.com/questions/4461586/how-do-i-convert-boostposix-timeptime-to-time-t]()

##手动指定timezone计算utc
```
using namespace boost;
date_time::local_adjustor<ptime, +8, posix_time::no_dst> tz_beijing;
/// todo
ptime pt_local = from_iso_string(iso_fmt);
ptime pt_utc = tz_beijing.local_to_utc(pt_local);
return (pt_utc - epoch).total_milliseconds();
```