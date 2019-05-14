using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;

namespace MapEditor
{
    
    class CObject
    {
        
        private int id;
        public Rectangle region;
       
        public int type;
        public int idName;
        public int direction;
        public int ID { get => id; }

        public CObject(int id, Rectangle region, string idName, int type, int direction)
        {
            this.id = id;
            this.region = region;
            switch(idName)
            {
                case "Dagger":
                    this.idName = (int)eType.Dagger;
                    break;
                case "BrownBird":
                    this.idName = (int)eType.BrownBird;
                    break;
                case "Blade":
                    this.idName = (int)eType.Blade;
                    break;
                case "Panther":
                    this.idName = (int)eType.Panther;
                    break;
                case "BombGun":
                    this.idName = (int)eType.BombGun;
                    break;
                case "Footballguy":
                    this.idName = (int)eType.Footballguy;
                    break;
                case "GunRage":
                    this.idName = (int)eType.GunRage;
                    break;
                case "BRICK":
                    this.idName = (int)eType.BRICK;
                    break;
                case "GATE":
                    this.idName = (int)eType.GATE;
                    break;
                case "STAIR":
                    this.idName = (int)eType.STAIR;
                    break;
            }
            switch(direction)
            {
                case 0:
                    this.direction = -1;
                    break;
                case 1:
                    this.direction = 1;
                    break;

            }
           
            this.type = type;
            
        }
        public string Output()
        {
            string output;
            output = (id+1).ToString() + " " + idName.ToString() + " " + direction.ToString() + " " + region.X.ToString() + " " + region.Y.ToString() + " " + region.Width.ToString()+" "+region.Height.ToString();
            return output;
        }
    }
    enum eType
    {
        NINJA = 01,
        NINJA_TRANS = 02,
        NINJA_DEADTH = 03,

        // object nền(Bat Dau 20)
        BRICK = 20,
        GATE = 21,

        // object(Bat Dau 40)
        STAIR = 40,


        // weapon(Bat Dau 60)


        // item(Bat Dau 80)


        // other (Bat Dau 100)
        Map1 = 100,
        Map2 = 101,
        Map3 = 102,

        // Effect(Bat Dau 100)


        // Enemy(Bat Dau 120)
        Dagger = 120,
        BrownBird = 121,
        Blade = 122,
        Panther = 123,
        BombGun = 124,
        Footballguy = 125,
        GunRage = 126,
        Ememy_Texture = 127,

        //BOSS(Bat Dau 140)
        BOSS = 140

        // Intro(Bat Dau 160)

    };
}
