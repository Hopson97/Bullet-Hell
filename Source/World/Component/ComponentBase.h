#ifndef COMPONENTBASE_H_INCLUDED
#define COMPONENTBASE_H_INCLUDED

class WorldObject;

class ComponentBase
{
    public:
        ComponentBase(WorldObject& object)
        :   m_pObject   (&object)
        { }

        virtual void update(float dt) = 0;

    protected:
        WorldObject* m_pObject;
};

#endif // COMPONENTBASE_H_INCLUDED
