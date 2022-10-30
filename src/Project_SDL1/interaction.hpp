class Interaction
{
    public:
        Interaction();
        ~Interaction();
        virtual Interaction interact (const Interaction &other); // virtual method;

        // getter and setter
        void set_nb_sheep(int x);
        int get_nb_sheep() const;
        void set_nb_wolves(int y);
        int get_nb_wolves() const;

    private:
        int nb_sheep;
        int nb_wolves;

};