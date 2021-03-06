/* Copyright (c) 2010-2011, Code Aurora Forum. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */
#ifndef _VIDEO_720P_RESOURCE_TRACKER_H_
#define _VIDEO_720P_RESOURCE_TRACKER_H_

#include <linux/regulator/consumer.h>
#include "vcd_res_tracker_api.h"
#ifdef CONFIG_MSM_BUS_SCALING
#include <mach/msm_bus.h>
#include <mach/msm_bus_board.h>
#endif

#define RESTRK_1080P_VGA_PERF_LEVEL    VCD_MIN_PERF_LEVEL
#define RESTRK_1080P_720P_PERF_LEVEL   108000
#define RESTRK_1080P_1080P_PERF_LEVEL  244800

#define RESTRK_1080P_MIN_PERF_LEVEL RESTRK_1080P_VGA_PERF_LEVEL
#define RESTRK_1080P_MAX_PERF_LEVEL RESTRK_1080P_1080P_PERF_LEVEL
struct res_trk_context {
	struct device *device;
	u32 irq_num;
	struct mutex lock;
	struct clk *vcodec_clk;
	struct clk *vcodec_pclk;
	unsigned long vcodec_clk_rate;
	unsigned int clock_enabled;
	unsigned int perf_level;
	struct regulator *footswitch;
#ifdef CONFIG_MSM_BUS_SCALING
	struct msm_bus_scale_pdata *vidc_bus_client_pdata;
	uint32_t     pcl;
#endif
	u32 core_type;
	u8 *base_addr;
	phys_addr_t device_addr;
};

#if DEBUG

#define VCDRES_MSG_LOW(xx_fmt...)	printk(KERN_INFO "\n\t* " xx_fmt)
#define VCDRES_MSG_MED(xx_fmt...)	printk(KERN_INFO "\n  * " xx_fmt)

#else

#define VCDRES_MSG_LOW(xx_fmt...)
#define VCDRES_MSG_MED(xx_fmt...)

#endif

#define VCDRES_MSG_HIGH(xx_fmt...)	printk(KERN_WARNING "\n" xx_fmt)
#define VCDRES_MSG_ERROR(xx_fmt...)	printk(KERN_ERR "\n err: " xx_fmt)
#define VCDRES_MSG_FATAL(xx_fmt...)	printk(KERN_ERR "\n<FATAL> " xx_fmt)

#endif
