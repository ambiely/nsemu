#ifndef _DISASSEMBLER_HPP
#define _DISASSEMBLER_HPP

enum {
        COND_EQ = 0,
        COND_NE,
};
class DisasCallback {
public:
/* Mov with Immediate value */
virtual void MoviI64(unsigned int reg_idx, uint64_t imm, bool unchanged, bool bit64) = 0;

/* Mov between registers */
virtual void MovReg(unsigned int rd_idx, unsigned int rn_idx, bool bit64) = 0;

/* Add/Sub with Immediate value */
virtual void AddI64(unsigned int rd_idx, unsigned int rn_idx, uint64_t imm, bool setflags, bool bit64) = 0;
virtual void SubI64(unsigned int rd_idx, unsigned int rn_idx, uint64_t imm, bool setflags, bool bit64) = 0;

/* Add/Sub between registers */
virtual void AddReg(unsigned int rd_idx, unsigned int rn_idx, unsigned int rm_idx, bool setflags, bool bit64) = 0;
virtual void SubReg(unsigned int rd_idx, unsigned int rn_idx, unsigned int rm_idx, bool setflags, bool bit64) = 0;

/* AND/OR/EOR/Shift ... with Immediate value */
virtual void AndI64(unsigned int rd_idx, unsigned int rn_idx, uint64_t wmask, bool setflags, bool bit64) = 0;
virtual void OrrI64(unsigned int rd_idx, unsigned int rn_idx, uint64_t wmask, bool bit64) = 0;
virtual void EorI64(unsigned int rd_idx, unsigned int rn_idx, uint64_t wmask, bool bit64) = 0;
virtual void ShiftI64(unsigned int rd_idx, unsigned int rn_idx, unsigned int shift_type, unsigned int shift_amount, bool bit64) = 0;

/* AND/OR/EOR/BIC/NOT... between registers */
virtual void AndReg(unsigned int rd_idx, unsigned int rn_idx, unsigned int rm_idx, bool setflags, bool bit64) = 0;
virtual void OrrReg(unsigned int rd_idx, unsigned int rn_idx, unsigned int rm_idx, bool bit64) = 0;
virtual void EorReg(unsigned int rd_idx, unsigned int rn_idx, unsigned int rm_idx, bool bit64) = 0;
virtual void BicReg(unsigned int rd_idx, unsigned int rn_idx, unsigned int rm_idx, bool setflags, bool bit64) = 0;
virtual void NotReg(unsigned int rd_idx, unsigned int rm_idx, bool bit64) = 0;
virtual void ExtendReg(unsigned int rd_idx, unsigned int rn_idx, unsigned int extend_type, bool bit64) = 0;

/* Bitfield Signed/Unsigned Extract... with Immediate value */
virtual void SExtractI64(unsigned int rd_idx, unsigned int rn_idx, unsigned int pos, unsigned int len, bool bit64) = 0;
virtual void UExtractI64(unsigned int rd_idx, unsigned int rn_idx, unsigned int pos, unsigned int len, bool bit64) = 0;

/* Go to Immediate address */
virtual void BranchI64(uint64_t imm) = 0;

/* Conditional Branch with Immediate value and jump to Immediate address */
virtual void BranchCondiI64(unsigned int cond, unsigned int rt_idx, uint64_t imm, uint64_t addr, bool bit64) = 0;

/* Conditional Branch with NZCV flags */
virtual void BranchFlag(unsigned int cond, uint64_t addr) = 0;

/* Set PC with reg */
virtual void SetPCReg(unsigned int rt_idx) = 0;

/* Super Visor Call */
virtual void SVC(unsigned int svc_num) = 0;
};

namespace Disassembler {

void DisasA64(uint32_t insn, DisasCallback *cb);

};

#endif
