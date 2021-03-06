/*
--------------------------------------------------------------------------------
This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Library General Public
License as published by the Free Software Foundation; either
version 2 of the License, or (at your option) any later version.
This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Library General Public License for more details.
You should have received a copy of the GNU Library General Public
License along with this library; if not, write to the
Free Software Foundation, Inc., 51 Franklin St, Fifth Floor,
Boston, MA  02110-1301, USA.
--------------------------------------------------------------------------------
*/

// Copyright (c) 2015 John Seamons, ZL/KF6VO

#pragma once

#include "types.h"
#include "kiwi.h"
#include "cuteSDR.h"

// sound
struct snd_t {
	u4_t seq;
    #ifdef SND_SEQ_CHECK
        bool snd_seq_init;
	    u4_t snd_seq;
    #endif
};

extern snd_t snd_inst[RX_CHANS];

struct snd_pkt_t {
	struct {
		char id[4];
		u4_t seq;           // waterfall syncs to this sequence number on the client-side
		char smeter[2];
	} __attribute__((packed)) h;
	union {
        u1_t buf_iq[FASTFIR_OUTBUF_SIZE * 2 * sizeof(u2_t)];
        u1_t buf_real[FASTFIR_OUTBUF_SIZE * sizeof(u2_t)];
    };
} __attribute__((packed));
