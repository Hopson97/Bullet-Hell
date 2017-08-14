#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED

class Enemy : public GameObject
{
    public:
        Enemy(Player& player);

        void update();

    private:

};

#endif // ENEMY_H_INCLUDED
