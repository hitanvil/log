spdlog initilization is encapuslated as `log_init()` which is defined in `log.h`:
```
void log_init(spdlog::level::level_enum console_level,
                 spdlog::level::level_enum file_level)
```

1. `log_init()` should be called at `main()` to initilize spdlog default logger for later use;
2. When `spdlog_init()` is called, it creates two sink, one is console, the other is to file. If one of them are not necessary, its level can be set to `spdlog::level::off`;
3. Predefined MARCO `LOG_TRACE`, `LOG_DBG`, `LOG_INFO`, `LOG_WARN`, `LOG_ERR` and `LOG_CRITICAL` should be used to output log with right format;
4. `phtread` is used in this encapuslation. So `-lpthread` should be specified to link pthread library;
5. Most of time, only `LOG_DBG`, `LOG_INFO`, `LOG_WARN` and `LOG_ERR` are used in code.