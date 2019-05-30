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
       
        public int idName;
        public int multiFunc;
        public string ReverseLo_Start;
        public string ReverseLo_End;
        public int ID { get => id; }

        public CObject(int id, Rectangle region, string idName, string MultiFunc, string ReverseLo_Start, string ReverseLo_End)
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
                case "BlackBird":
                    this.idName = (int)eType.Black_Bird;
                    break;
                case "Butterfly":
                    this.idName = (int)eType.ButterFly;
                    break;
            }
            switch(MultiFunc)
            {
                case "RIGHT":
                    this.multiFunc = 1;
                    break;
                case "LEFT":
                    this.multiFunc = -1;
                    break;
                case "ItemBluePoint":
                    this.multiFunc = (int)eType.Item_Blue_Point;
                    break;
                case "ItemRedPoint":
                    this.multiFunc = (int)eType.Item_Red_Point;
                    break;
                case "ItemBlueShuriken":
                    this.multiFunc = (int)eType.Item_BlueShuriken;
                    break;
                case "ItemRedShuriken":
                    this.multiFunc = (int)eType.Item_RedShuriken;
                    break;
                case "ItemBlueStack":
                    this.multiFunc = (int)eType.Item_BlueStack;
                    break;
                case "ItemRedStack":
                    this.multiFunc = (int)eType.Item_RedStack;
                    break;
                case "ItemHealth":
                    this.multiFunc = (int)eType.Item_Heath;
                    break;
                case "ItemHadoken":
                    this.multiFunc = (int)eType.Item_Hadoken;
                    break;
                case "ItemFreezeTime":
                    this.multiFunc = (int)eType.Item_RedStack;
                    break;
            }
            this.ReverseLo_Start = ReverseLo_Start;
            this.ReverseLo_End = ReverseLo_End;
        }
        public string Output()
        {
            string output;
            output = idName.ToString() + " " + multiFunc.ToString() + " " + region.X.ToString() + " " + region.Y.ToString() + " " + region.Width.ToString()+" "+region.Height.ToString()+" "+ReverseLo_Start+" "+ReverseLo_End;
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
        BASICWEAPON = 60,
        BlueShuriken = 61,


        // item(Bat Dau 80)
        Black_Bird = 80,
        ButterFly = 81,
        Item_BlueShuriken = 82,
        Item_RedShuriken = 83,
        Item_Freeze_Time = 84,
        Item_BlueStack = 85,
        Item_RedStack = 86,
        Item_Hadoken = 87,
        Item_Heath = 88,
        Item_Blue_Point = 89,
        Item_Red_Point = 90,

        // other (Bat Dau 100)
        Map1 = 100,
        Map2 = 101,
        Map3 = 102,
        BBOX = 103,



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
        // Effect(Bat Dau 180)
    };
}
