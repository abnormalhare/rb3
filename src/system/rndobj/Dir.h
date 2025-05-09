#pragma once
#include "obj/Msg.h" // MsgSource : public virtual Object
#include "rndobj/Poll.h" // RndPollable : public virtual Object
#include "rndobj/Trans.h" // RndTransformable : public virtual RndHighlightable
#include "rndobj/Anim.h" // RndAnimatable : public virtual Object
#include "rndobj/Draw.h" // RndDrawable : public virtual RndHighlightable
#include "obj/Dir.h" // ObjectDir : public virtual Object
#include "types.h"
#include <vector>
#include "obj/Object.h"
#include "obj/ObjPtr_p.h"
#include "rndobj/Env.h"

/**
 * @brief An ObjectDir dedicated to holding Rnd* objects.
 * Original _objects description:
 * "A RndDir specially tracks drawable and animatable objects."
 */
class RndDir : public ObjectDir,
               public RndDrawable,
               public RndAnimatable,
               public RndTransformable,
               public RndPollable,
               public MsgSource {
public:
    RndDir();
    OBJ_CLASSNAME(RndDir)
    OBJ_SET_TYPE(RndDir)
    virtual DataNode Handle(DataArray *, bool);
    virtual bool SyncProperty(DataNode &, DataArray *, int, PropOp);
    virtual void Save(BinStream &);
    virtual void Copy(const Hmx::Object *, CopyType);
    virtual void Load(BinStream &);
    virtual ~RndDir() {}
    virtual void SetSubDir(bool);
    virtual void PreLoad(BinStream &);
    virtual void PostLoad(BinStream &);
    virtual void SyncObjects();
    virtual void RemovingObject(Hmx::Object *);
    virtual void OldLoadProxies(BinStream &, int);
    virtual void Replace(Hmx::Object *, Hmx::Object *);
    virtual void UpdateSphere();
    virtual float GetDistanceToPlane(const Plane &, Vector3 &);
    virtual bool MakeWorldSphere(Sphere &, bool);
    virtual void DrawShowing();
    virtual RndDrawable *CollideShowing(const Segment &, float &, Plane &);
    virtual int CollidePlane(const Plane &);
    virtual void CollideList(const Segment &, std::list<Collision> &);
    virtual void ListDrawChildren(std::list<RndDrawable *> &);
    virtual void SetFrame(float, float);
    virtual float EndFrame();
    virtual void ListAnimChildren(std::list<RndAnimatable *> &) const;
    virtual void Poll();
    virtual void Enter();
    virtual void Exit();
    virtual void ListPollChildren(std::list<RndPollable *> &) const;
    virtual void Highlight() { RndDrawable::Highlight(); }
    virtual void Export(DataArray *, bool);
    virtual void ChainSourceSubdir(MsgSource *, ObjectDir *);

    void SyncDrawables();
    void CollideListSubParts(const Segment &, std::list<Collision> &);
    void SetEnv(RndEnviron *env) { mEnv = env; }
    RndEnviron *GetEnv() const { return mEnv; }

    /** Handler to show (or hide) all objects in the supplied DataArray.
     * @param [in] arr The supplied DataArray.
     * Expected DataArray contents:
     *     Node 2: a DataArray of all the objects to show/hide.
     *     Node 3: if 0, hide everything; else show everything.
     * Example usage: {$this show_objects (your_objects) TRUE}
     */
    DataNode OnShowObjects(DataArray *arr);
    /** Get a DataArray of all supported EventTrigger events in this RndDir.
     * @returns A DataNode housing the aforementioned DataArray.
     * Example usage: {$this supported_events}
     */
    DataNode OnSupportedEvents(DataArray *);

    DECLARE_REVS

    /** "List of all the draws" */
    std::vector<RndDrawable *> mDraws; // 0x164

    /** Animations for this dir. */
    std::vector<RndAnimatable *> mAnims; // 0x16c

    /** "List of all the polls" */
    std::vector<RndPollable *> mPolls; // 0x174

    /** The dedicated RndEnviron for this dir. */
    ObjPtr<RndEnviron> mEnv; // 0x17c

    /** "Test event" */
    Symbol mTestEvent; // 0x188

    NEW_OVERLOAD;
    DELETE_OVERLOAD;
    NEW_OBJ(RndDir)
    static void Init() { REGISTER_OBJ_FACTORY(RndDir) }
};
