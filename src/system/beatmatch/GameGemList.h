#pragma once
#include "beatmatch/GameGem.h"
#include <vector>

class GameGemList {
public:
    GameGemList(int);
    void Clear();
    bool AddMultiGem(const MultiGemInfo &);
    bool AddRGGem(const RGGemInfo &);
    void MergeChordGems();
    void Finalize();
    void CopyFrom(const GameGemList *);
    float TimeAt(int) const;
    float TimeAtNext(int) const;
    void Reset();
    int ClosestMarkerIdx(float) const;
    int ClosestMarkerIdxAtOrAfter(float) const;
    bool AddGameGem(const GameGem &, NoStrumState);
    void RecalculateGemTimes(TempoMap *);
    bool WillBeNoStrum(const GameGem &);
    int ClosestMarkerIdxAtOrAfterTick(int) const;
    void SetGems(int, int, int, const std::vector<GameGem> &, int);

    int NumGems() const { return mGems.size(); }
    bool Empty() const { return mGems.empty(); }

    GameGem &GetGem(int id) {
        MILO_ASSERT(0 <= id && id < NumGems(), 0x3A);
        return mGems[id];
    }

    const GameGem &GetGem(int id) const {
        MILO_ASSERT(0 <= id && id < NumGems(), 0x40);
        return mGems[id];
    }

    int mHopoThreshold;
    std::vector<GameGem> mGems;
};

bool GameGemCmp(const GameGem &gem, float ms);
