# unirtos-fota-demos

中文 | [English](README.md)

本仓库推荐通过 unirtos-cli 的 demo 工作流使用，以保证创建、环境拉取和编译流程一致。

## 概述

`unirtos-fota-demos` 用于展示 UniRTOS 下 FOTA（Firmware Over-The-Air，空中固件升级）能力的整体方案。  
该目录聚焦远程升级相关示例，覆盖从固件下载到升级流程集成的典型场景，便于快速理解 FOTA 能力边界与传输协议的选型方向。

FOTA 是嵌入式设备实现远程固件维护的核心机制。UniRTOS 提供了完整的 FOTA 支持框架，支持通过多种传输协议（如 FTP、HTTP）获取固件包，并经由统一的升级写入接口完成固件替换与重启激活。本目录提供多个典型场景示例，供开发者参考选型并快速集成到自己的产品升级流程中。

## 功能描述

- 支持基于 **FTP** 协议的固件下载与升级流程（见 [ftp-fota-demos](./ftp-fota-demos/)）
- 支持基于 **HTTP** 协议的固件下载与升级流程（见 [http-fota-demos](./http-fota-demos/)）
- 统一覆盖 FOTA 全流程：PDP 激活 → 固件下载 → 写入升级模块 → 结果处理
- 各子 Demo 均可独立编译运行，并包含完整的错误处理与日志输出
- 便于扩展为带认证、断点续传、多版本管理及量产级升级编排等高级场景

## 子 Demo 说明

| 子 Demo | 传输协议 | 说明 |
|---|---|---|
| [ftp-fota-demos](./ftp-fota-demos/) | FTP | 通过 FTP 客户端下载固件包，适合内网或私有服务器分发场景 |
| [http-fota-demos](./http-fota-demos/) | HTTP | 通过 HTTP GET 下载固件，支持定长与分块传输，适合公网 OTA 服务分发场景 |

## 快速上手

### 1. 安装 UniRTOS 工具链

- [开发准备](https://www.quectel.com.cn/unirtos/docs?docs_page=快速上手/开发准备/开发准备.html)
- [安装交叉编译工具链](https://www.quectel.com.cn/unirtos/docs?docs_page=快速上手/环境搭建/环境搭建.html)
- [安装 Python3](https://www.python.org/downloads/)
- [安装 git](https://git-scm.com)
- 安装 unirtos-cli：`pip install unirtos-cli`

安装完成后，确认以下命令可用：

```bash
python --version       # Python3
git --version
unirtos --version      # 1.0.5 及以上版本
unirtos-cli version    # 1.0.11 及以上版本
```

### 2. 使用 unirtos-cli 拉取 demo

查看可用 demo 与版本：

```bash
unirtos-cli ls-demos
```

创建本 demo 工程：

```bash
unirtos-cli new -r unirtos-fota-demos
```

如需指定版本：

```bash
unirtos-cli new -r unirtos-fota-demos -v 1.0.0
```

### 3. 进入子 Demo 目录并编译

选择所需传输协议的子 Demo，例如 HTTP FOTA：

```bash
cd unirtos-fota-demos-1.0.0/http-fota-demos
unirtos-cli env-setup
unirtos-cli build
```

FTP FOTA：

```bash
cd unirtos-fota-demos-1.0.0/ftp-fota-demos
unirtos-cli env-setup
unirtos-cli build
```

## 常用命令

```bash
# 打开 SDK 菜单配置
unirtos-cli menuconfig

# 清理构建产物
unirtos-cli clean
```

## 目录结构

```
unirtos-fota-demos/
├── README.md
├── README.zh.md
├── ftp-fota-demos/                # 基于 FTP 的 FOTA 升级示例
│   ├── CMakeLists.txt
│   ├── env_config.json
│   ├── ftp_fota_demo.c            # FTP 固件下载与升级主逻辑
│   ├── ftp_fota_demo.h
│   ├── menuconfig/
│   ├── README.md
│   └── README.zh.md
└── http-fota-demos/               # 基于 HTTP 的 FOTA 升级示例
    ├── CMakeLists.txt
    ├── env_config.json
    ├── http_fota_demo.c           # HTTP 固件下载与升级主逻辑
    ├── http_fota_demo.h
    ├── menuconfig/
    ├── README.md
    └── README.zh.md
```

## 选型参考

| 场景 | 推荐方案 |
|---|---|
| 设备连接私有 FTP 服务器，网络环境受控 | ftp-fota-demos |
| 设备通过公网 HTTP/HTTPS 服务器获取固件 | http-fota-demos |
| 需要断点续传（Range 请求）支持 | http-fota-demos（可扩展） |
| 需要用户名/密码认证的私有服务 | ftp-fota-demos（可扩展） |

## 技术社区

技术社区：https://forumschinese.quectel.com/c/66-category/66

## 贡献指南

欢迎参与共建，建议按以下方式提交：
- 提交前先执行一次基础验证：env-setup、build、clean。
- 使用清晰的提交说明，描述改动目的、影响范围和验证结果。
- 新增功能或行为变化时，同步更新 README 与相关文档。
- 通过 Issue 或 Pull Request 提交问题修复与功能改进。
