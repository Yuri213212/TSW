const wchar_t szAppName[]=			L"TSW";
const wchar_t szTitle[]=			L"魔塔";

const wchar_t szErr_OpenFile[]=			L"无法打开%s！";
const wchar_t szErr_RegisterClass[]=		L"RegisterClass失败！";
const wchar_t szErr_Logic[]=			L"出现了逻辑错误，请联系作者。";
const wchar_t szErr_Save[]=			L"在剧情模式禁止存盘。";
const wchar_t szQuestion_NewGameConfirm[]=	L"你确定要进行新游戏吗？\n所有存档都将重置。";
const wchar_t szUI_Weapon[]=			L"武器";
const wchar_t szUI_Armor[]=			L"防具";
const wchar_t szUI_Round[]=			L"第%d轮";
const wchar_t szUI_Tower[]=			L"魔塔";
const wchar_t szUI_Floor[]=			L"楼";
const wchar_t szMenu_New[]=			L"新游戏";
const wchar_t szMenu_Load[]=			L"读盘";
const wchar_t szMenu_Save[]=			L"存盘";
const wchar_t szMenu_Help[]=			L"帮助";
#ifdef DEBUG
const wchar_t szMenu_Debug[]=			L"测试";
const wchar_t szMenu_Life[]=			L"生命";
const wchar_t szMenu_Attack[]=			L"攻击";
const wchar_t szMenu_Defend[]=			L"防御";
const wchar_t szMenu_Gold[]=			L"金币";
const wchar_t szMenu_Key[]=			L"钥匙";
const wchar_t szMenu_Item[]=			L"道具";
#endif

const wchar_t * const aszWeaponName[]={
	L"铁剑",
	L"银剑",
	L"骑士剑",
	L"圣剑",
	L"神圣剑",
};

const wchar_t * const aszArmorName[]={
	L"铁盾",
	L"银盾",
	L"骑士盾",
	L"圣盾",
	L"神圣盾",
};

const wchar_t szCell_BraveMan[]=		L"勇者";
const wchar_t szCell_Thief[]=			L"小偷";
const wchar_t szCell_Princess[]=		L"公主";
const wchar_t szCell_OldMan[]=			L"老人";
const wchar_t szCell_Merchant[]=		L"商人";
const wchar_t szCell_Altar[]=			L"祭坛";

const wchar_t szCell_Stair[]=			L"楼梯";
const wchar_t szCell_FakeWall[]=		L"假墙";
const wchar_t szCell_FakeRoad[]=		L"假路";
const wchar_t szCell_RedDoor[]=			L"红门";
const wchar_t szCell_BlueDoor[]=		L"蓝门";
const wchar_t szCell_YellowDoor[]=		L"黄门";
const wchar_t szCell_Lava[]=			L"岩浆";

const wchar_t szCell_GreenSlime[]=		L"绿史莱姆";
const wchar_t szCell_RedSlime[]=		L"红史莱姆";
const wchar_t szCell_Bat[]=			L"小蝙蝠";
const wchar_t szCell_Priest[]=			L"初级牧师";
const wchar_t szCell_SkeletonC[]=		L"骷髅人";
const wchar_t szCell_SkeletonB[]=		L"骷髅士兵";
const wchar_t szCell_GateKeeperC[]=		L"初级门卫";
const wchar_t szCell_SkeletonA[]=		L"骷髅队长";
const wchar_t szCell_BigSlime[]=		L"大史莱姆";
const wchar_t szCell_BigBat[]=			L"大蝙蝠";
const wchar_t szCell_Zombie[]=			L"僵尸";
const wchar_t szCell_SuperionPriest[]=		L"高级牧师";
const wchar_t szCell_Rock[]=			L"石头人";
const wchar_t szCell_ZombieKnight[]=		L"僵尸骑士";
const wchar_t szCell_Vampire[]=			L"吸血鬼";
const wchar_t szCell_SlimeMan[]=		L"史莱姆人";
const wchar_t szCell_GhostSoldier[]=		L"幽灵士兵";
const wchar_t szCell_Soldier[]=			L"士兵";
const wchar_t szCell_Swordsman[]=		L"双手剑士";
const wchar_t szCell_Knight[]=			L"骑士";
const wchar_t szCell_GateKeeperB[]=		L"中级门卫";
const wchar_t szCell_GoldenKnight[]=		L"金骑士";
const wchar_t szCell_SlimeLord[]=		L"史莱姆王";
const wchar_t szCell_VampireBat[]=		L"吸血蝙蝠";
const wchar_t szCell_MagicianB[]=		L"初级巫师";
const wchar_t szCell_MagicianA[]=		L"高级巫师";
const wchar_t szCell_MagicSergeant[]=		L"魔法警官";
const wchar_t szCell_DarkKnight[]=		L"黑暗骑士";
const wchar_t szCell_GateKeeperA[]=		L"高级门卫";
const wchar_t szCell_GiantOctopus[]=		L"大章鱼";
const wchar_t szCell_Dragon[]=			L"龙";
const wchar_t szCell_GreatMagicMaster[]=	L"大魔法师";
const wchar_t szCell_Zeno[]=			L"魔王";

const wchar_t szCell_RedKey[]=			L"红钥匙";
const wchar_t szCell_BlueKey[]=			L"蓝钥匙";
const wchar_t szCell_YellowKey[]=		L"黄钥匙";
const wchar_t szCell_RedElixir[]=		L"红药水";
const wchar_t szCell_BlueElixir[]=		L"蓝药水";
const wchar_t szCell_RedCrystal[]=		L"红水晶";
const wchar_t szCell_BlueCrystal[]=		L"蓝水晶";
const wchar_t szCell_IronSword[]=		L"铁剑";
const wchar_t szCell_SilverSword[]=		L"银剑";
const wchar_t szCell_SwordOfKnight[]=		L"骑士剑";
const wchar_t szCell_HolySword[]=		L"圣剑";
const wchar_t szCell_SacredSword[]=		L"神圣剑";
const wchar_t szCell_IronShield[]=		L"铁盾";
const wchar_t szCell_SilverShield[]=		L"银盾";
const wchar_t szCell_ShieldOfKnight[]=		L"骑士盾";
const wchar_t szCell_HolyShield[]=		L"圣盾";
const wchar_t szCell_SacredShield[]=		L"神圣盾";

const wchar_t szCell_OrbOfHero[]=		L"英雄之球";
const wchar_t szCell_OrbOfWisdom[]=		L"智慧之球";
const wchar_t szCell_OrbOfFlying[]=		L"飞行之球";
const wchar_t szCell_Cross[]=			L"十字架";
const wchar_t szCell_MagicElixir[]=		L"魔法药水";
const wchar_t szCell_MagicMattock[]=		L"镐";
const wchar_t szCell_DestructibleBall[]=	L"炸弹";
const wchar_t szCell_WarpStaff[]=		L"传送权杖";
const wchar_t szCell_WingsToFlyUp[]=		L"上升翼";
const wchar_t szCell_WingsToFlyDown[]=		L"下降翼";
const wchar_t szCell_DragonSlayer[]=		L"屠龙刀";
const wchar_t szCell_SnowCrystal[]=		L"雪水晶";
const wchar_t szCell_MagicKey[]=		L"魔法钥匙";
const wchar_t szCell_SuperMagicMattock[]=	L"超级镐";
const wchar_t szCell_LuckyGold[]=		L"幸运金币";

const wchar_t szScreen_Load[]=			L"\n读档\n\n\n按数字键读取对应的档。\n按Esc返回。";
const wchar_t szScreen_LoadNull[]=		L"不可用";
const wchar_t szScreen_LoadStatus[]=		L"%d:%2dF,R%5d\n血%10d\n攻%10d\n防%10d";
const wchar_t szScreen_Book[]=			L"查看打怪结果\n按Esc返回。";
const wchar_t szScreen_StrongEnemy[]=		L"无法攻击";
const wchar_t szScreen_Note[]=			L"回顾重要信息\n按Home/End翻页，按Esc返回。";

const wchar_t szScreen_PressEnter[]=		L"按回车键继续。";
const wchar_t szScreen_Coma1[]=			L"行动时机至，";
const wchar_t szScreen_Coma2[]=			L"全知之力使。";
const wchar_t szScreen_Coma3[]=			L"打破神圣剑，";
const wchar_t szScreen_Coma4[]=			L"获得大启示。";
const wchar_t szScreen_Finale1[]=		L"长战结束，傲塔既仆。";
const wchar_t szScreen_Finale2[]=		L"神回天府，兵归故土。";
const wchar_t szScreen_Finale3[]=		L"今已为古，此旅亦故。";
const wchar_t szScreen_Finale4[]=		L"汝当回顾，再踏新途。";
const wchar_t szScreen_TheEnd[]=		L"剧终";

const wchar_t szDialog_Wake1[]=			L"…";
const wchar_t szDialog_Wake2[]=			L"……";
const wchar_t szDialog_Wake3[]=			L"……喂！";
const wchar_t szDialog_Wake4[]=			L"……喂！醒醒！";
const wchar_t szDialog_Story3F1[]=		L"欢迎来到魔塔。\n你是第100个胆敢闯入我的塔的人。\n你将直面我的守卫们，\n要是你侥幸活下来的话，\n我将破例和你单挑，\n这就是你的命运。";
const wchar_t szDialog_Story3F2[]=		L"什么？\n啊！";
const wchar_t szDialog_Story10F1[]=		L"哈哈哈，能闯到我这里算你走运。\n既然你来了，我将与你单挑，\n不过你必须先证明你的力量。\n进攻，骷髅士兵们！";
const wchar_t szDialog_Story10F2[]=		L"你很强，不过我不会让你通过，你将在这里死去。\n来打我啊！";
const wchar_t szDialog_Story10F3[]=		L"不，这不可能！\n虽然你打败了我，\n但是从这之后你将遇到更强的敌人与圈套。\n你要是一个不留神，就会死！";
const wchar_t szDialog_Story10F4[]=		L"嘿，我们又见面了！\n多亏你把这个区域的头目打得落花流水，\n我本以为我不能再上楼了呢。\n我听说11楼有一面盾17楼有一把剑，\n我要是你的话就会去拿它们。\n恕我先走一步。";
const wchar_t szDialog_Story20F1[]=		L"好吧，你打败了骷髅们闯了进来，\n但是你不许把我视为一个小骷髅。\n我要让你瞧瞧我像神一样的永生。\n嘿，来吧！";
const wchar_t szDialog_Story20F2[]=		L"我的老天爷，我做梦都没想到我会被打败。\n你的力量毋庸置疑，\n但是以你这么弱你不可能打败大魔法师。\n你顶多能庆祝一下这暂时的胜利。";
const wchar_t szDialog_Story25F[]=		L"杀～死～入～侵～者～";
const wchar_t szDialog_Story32F1[]=		L"能打败第一第二区域头目上来，你的确是个勇者，\n不过现在游戏结束了。\n此时此地，我要亲手击败你，投降吧！";
const wchar_t szDialog_Story32F2[]=		L"你以为你很强吗？哈？\n如果你能顺利到达40楼，我将和你再战，\n那将是你的葬身之处！";
const wchar_t szDialog_Story40F1[]=		L"我纳闷你是怎么过来的，不过你休想再前进一步。\n我要将你给本塔的耻辱10倍奉还。\n幽灵士兵们，冲锋！";
const wchar_t szDialog_Story40F2[]=		L"哼，不管用吗？\n士兵们，冲锋！";
const wchar_t szDialog_Story40F3[]=		L"这仅仅是个开始，咱们继续打。\n双手剑士们，冲锋！";
const wchar_t szDialog_Story40F4[]=		L"我尻！\n那这个攻击怎么样？\n骑士们，冲锋！";
const wchar_t szDialog_Story40F5[]=		L"你竟敢击败我的全部随从，我与你不共戴天！\n现在我要动真格的了，投降吧！";
const wchar_t szDialog_Story40F6[]=		L"这次我不得不放你一马，\n不过下次再会时我们再认真地打一场，\n那时你最好投降！";
const wchar_t szDialog_Story42F1[]=		L"哦！魔王长官，我没能抓住那个勇者。\n请饶了我。";
const wchar_t szDialog_Story42F2[]=		L"你没做到？你还敢再说出口？\n你跟个懦夫似的逃到这里还说你不能完成你的工作，\n真丢人！\n这塔不需要你这样的垃圾！\n这是你最后一次令我失望了，去死吧！";
const wchar_t szDialog_Story42F3[]=		L"我的天啊，饶命啊！\n啊！";
const wchar_t szDialog_Story42F4[]=		L"我做得有失身份了，\n不过别怕，我和那家伙不一样。\n如果你能到我面前，我将直接与你战斗，\n我期待着你。";
const wchar_t szDialog_Story49F1[]=		L"好神奇，你到底还是找到来这里的路了，我恭喜你。\n现在，就像我承诺的，我会和你一对一地决斗。";
const wchar_t szDialog_Story49F2[]=		L"啊啦。。。";
const wchar_t szDialog_Story50F1[]=		L"谁？\n原来是你！你为什么在这里？";
const wchar_t szDialog_Story50F2[]=		L"嗯，我在这里的唯一原因嘛，\n就是这个！";
const wchar_t szDialog_Story50F3[]=		L"哈？\n喂！你是魔王啊！你还活着吗？";
const wchar_t szDialog_Story50F4[]=		L"我是不会死的。\n我那只是在打探你作为一个士兵的情报。";
const wchar_t szDialog_Story50F5[]=		L"哈？你说的是什么意思？\n你为什么要这么做？";
const wchar_t szDialog_Story50F6[]=		L"传说能够融合斗志（你的神圣剑）\n和知性（我的全知权杖）的人会得到大智慧。\n为了达成这个目标，\n需要保证那个使用神圣剑的士兵能够控制它的力量。";
const wchar_t szDialog_Story50F7[]=		L"你在说。。。我就是那个士兵？";
const wchar_t szDialog_Story50F8[]=		L"对，你说得没错。\n可是当你刚来这的时候，\n你还没有足够的能力来掌控神圣剑。\n因此我给了你错误的信息，\n在这座塔里设下层层圈套等你出现。\n正如我事先规划好的，你果然获得了足够的力量，\n掌控了神圣剑，并到达了这里。";
const wchar_t szDialog_Story50F9[]=		L"好吧，这意味着公主被关在这里的流言。。。\n是为了把我骗来的彻头彻尾的谎言，不是吗？";
const wchar_t szDialog_Story50F10[]=		L"对，没错。\n现在，如果我们合作，这场闹剧就结束了。\n行动时机至，\n全知之力使。\n打破神圣剑，\n获得大启示。\n神圣剑之士，\n与吾终于此！";
const wchar_t szDialog_Story50F11[]=		L"你个恶棍，我从未想过我会被你打败。\n不过我不能这么死去，我期待与你再战。";

const wchar_t szDialog_Thief2F1[]=		L"你还好真是万幸。\n你被魔法警官们抓住并扔到了这个监狱里，\n你来的时候已经昏迷了。\n尽管如此，你能醒来很幸运。\n我已经挖好了逃脱用的隧道，我们越狱吧。";
const wchar_t szDialog_Thief2F2[]=		L"好吧，恕我先走一步。\n你的武器和盾牌被卫兵们偷走了，\n手无寸铁地乱晃并不是一个好主意。\n我确信5楼有一把剑9楼有一面盾，\n总之你最好先拿到它们。\n再见！";
const wchar_t szDialog_Thief2F3[]=		L"啊，我们又见面了！\n谢谢你打败了这个区域的门卫。\n我被打败了，然后又被囚禁了，这回的监狱真小。\n我去35楼的龙前面挖隧道，你去35楼等我把隧道挖好。";
const wchar_t szDialog_Thief2F4[]=		L"别担心，我会在那里等你。";
const wchar_t szDialog_Thief15F[]=		L"啊，你还好吗？\n那只大章鱼挡住了我。\n现在洞终于打通了，你最好来日再打败他。\n再见！";
const wchar_t szDialog_Thief29F1[]=		L"隧道还未完成，你本该再等一会，而不是使用道具。\n我的计划出了点问题。\n好啦好啦，别怕。";
const wchar_t szDialog_Thief29F2[]=		L"哦，我终于完成了隧道。。。\n哇！又见到你了。\n你来的时机刚刚好，\n我已经打通了隧道，你可以自由地使用。";
const wchar_t szDialog_Thief29F3[]=		L"最终的头目和被抓的公主肯定在这个区域。\n嗯，我在想我们是不是应该等等再和他战斗。";
const wchar_t szDialog_Thief35F1[]=		L"你来了。\n我刚完成隧道，穿过它你将会绕过龙，然后就能上楼。";
const wchar_t szDialog_Thief35F2[]=		L"金骑士（本区域头目）虽然很弱但是态度强硬，\n因此被魔塔的副司令——魔王讨厌。";
const wchar_t szDialog_Thief50F[]=		L"啊，我们又见面了！\n谢天谢地你还活着！";

const wchar_t szDialog_Princess1[]=		L"时机已到，你是被选中的人。\n如果你不怕死，你就该穿越时空之门，到我这里来。";
const wchar_t szDialog_Princess2[]=		L"哦？什么？！这是个洋娃娃！";

const wchar_t szDialog_OldManT[]=		L"我已经尽力了，祝你好运。";
const wchar_t szDialog_OldMan2F[]=		L"哦，谢谢你的帮助。\n我将提升你3%的攻防。";
const wchar_t szDialog_OldMan3F[]=		L"我将授予你英雄之球。\n你现在可以存档（快捷键S），\n并且能预测与本层怪物战斗的结果。\n请经常使用。";
const wchar_t szDialog_OldMan4F[]=		L"有些门不能用钥匙打开，你必须击败看守它们的怪物。";
const wchar_t szDialog_OldMan6F[]=		L"如果你从商人那里买东西，\n你将会从他那听到重要的信息。";
const wchar_t szDialog_OldMan16F1[]=		L"我听说你可以在这个区域找到两把红钥匙。";
const wchar_t szDialog_OldMan16F2[]=		L"谢天谢地，你找到了我。\n我将给你一瓶魔法药水以表感谢。\n此药根据你的攻防增加生命值，\n因此越晚使用效果越好。";
const wchar_t szDialog_OldMan18F[]=		L"在此区域，你若不在祭坛多次提升攻击，\n你将无法击败石头人。\n请当心！";
const wchar_t szDialog_OldMan21F[]=		L"大魔法师在这个区域。\n他是这个魔塔的主人。\n以你现在的力量去攻击他就是找死。\n所以你不应该去找他，而应该先去更高层拿道具。";
const wchar_t szDialog_OldMan23F[]=		L"我无话可说，\n但是这个房间里可能隐藏着一个确切的消息。";
const wchar_t szDialog_OldMan27F[]=		L"在你刚到本层的时候，\n如果你生命1500，攻击80，防御98，\n拥有5把黄钥匙和1把蓝钥匙，\n那么你的状态近乎理想。";
const wchar_t szDialog_OldMan31F[]=		L"耍两把剑的双手剑士攻击力太高了。\n他能同时使用这两把剑，\n如果你和他正常地战斗你将失去很多生命值。\n因此不应该在你的攻击不如他的强的时候和他战斗。";
const wchar_t szDialog_OldMan33F[]=		L"事需缓图，欲速不达也。";
const wchar_t szDialog_OldMan36F[]=		L"如果你能用好本层的4个隧道，\n你不用打强敌就能上楼。";
const wchar_t szDialog_OldMan37F[]=		L"你需要镐来获得本层道具仓库里的宝物。";
const wchar_t szDialog_OldMan39F[]=		L"能让人在空间中旅行的神秘宝物将在3点钟出现。";
const wchar_t szDialog_OldMan42F[]=		L"当你接近魔法师的时候他将用魔法攻击你。\n两个魔法警官的夹击将令你的生命值减半。\n在你攻击两侧的魔法警官时，\n你越强受到的伤害越多，\n因此请格外小心。";
const wchar_t szDialog_OldMan45F[]=		L"这个塔的44楼是幻影，\n貌似即使使用楼梯也到不了那里。\n我觉得不用传送的话不可能去那里。";
const wchar_t szDialog_OldMan46F[]=		L"41楼是完美对称的，因此。。。";
const wchar_t szDialog_OldMan48F[]=		L"据说两个骰子5点的形状拥有封印魔法的力量。\n你最好记住这件事直到你去打这个区域的头目。";

const wchar_t szDialog_MerchantT[]=		L"除了“请当心”，我没有什么可说的了。";
const wchar_t szDialog_Merchant2F[]=		L"谢谢你的帮助。\n这些钱代表我的谢意，请收下。";
const wchar_t szDialog_Merchant2FB[]=		L"请明智地使用它们。";
const wchar_t szDialog_Merchant6F[]=		L"我将以一个特别的价钱卖给你1把蓝钥匙（50金币），\n你会买吗？";
const wchar_t szDialog_Merchant6FB[]=		L"这个魔塔有50层，每10层为1个区，每个区都有头目。\n如果你不打败他们，你不能上楼。";
const wchar_t szDialog_Merchant7F[]=		L"我将以50金币的价格卖给你5把黄钥匙，你会买吗？";
const wchar_t szDialog_Merchant7FB[]=		L"当你用金币供奉祭坛的时候，\n大多数情况下提升防御比提升攻击好。\n不过若你完全不提升攻击，\n你就无法打倒一些敌人。";
const wchar_t szDialog_Merchant12F1[]=		L"我将以800金币的价格卖给你1把稀有的红钥匙，你会买吗？";
const wchar_t szDialog_Merchant12FB[]=		L"你注意到9楼、16楼和18楼的密道了吗？";
const wchar_t szDialog_Merchant12F2[]=		L"我的商店不限量出售黄钥匙，每把1000金币，\n你会买它们吗？";
const wchar_t szDialog_Merchant15F[]=		L"我将以200金币的价格卖给你1把蓝钥匙，你会买吗？";
const wchar_t szDialog_Merchant15FB[]=		L"如果你携带十字架，僵尸和吸血鬼的生命值将减半。\n没有十字架几乎不能打败他们，尤其是吸血鬼。\n十字架在更上层。";
const wchar_t szDialog_Merchant28F[]=		L"我将以每把100金币的价格收购黄钥匙。\n你会卖给我吗？";
const wchar_t szDialog_Merchant31F[]=		L"我将以1000金币的价格卖给你4把黄钥匙\n和1把蓝钥匙，你会买吗？";
const wchar_t szDialog_Merchant31FB[]=		L"这塔有50层，不过事实上你貌似无法上到50楼。";
const wchar_t szDialog_Merchant38F[]=		L"我将以一个特别的价钱卖给你3把黄钥匙（200金币），\n先到先得。";
const wchar_t szDialog_Merchant38FB[]=		L"不存在没有门卫的大门，\n反过来有门卫的地方也一定有大门，\n所以。。。";
const wchar_t szDialog_Merchant39F[]=		L"2000金币换3把蓝钥匙，成交？";
const wchar_t szDialog_Merchant39FB[]=		L"在塔的某处有个幸运金币。\n有了它，在你打败敌人后会获得两倍金币。";
const wchar_t szDialog_Merchant45F[]=		L"我将以1000金币增加你2000点生命值。";
const wchar_t szDialog_Merchant45FB[]=		L"神圣盾可以抵御魔法攻击，\n不过我听说这个盾被藏在并不存在的楼层。";
const wchar_t szDialog_Merchant47F[]=		L"你会用4000金币买一个超级镐吗？（它非常稀有）";
const wchar_t szDialog_Merchant47FB[]=		L"如果你想打败龙，\n你必须拥有圣剑、圣盾和屠龙刀，\n同时你的等级也必须足够高。";

const wchar_t szDialog_Altar[]=			L"如果你给我%d枚金币，我会接受你的请求。\n\n请选择一项：\n<1> 增加%d点生命值\n<2> 提升%d点攻击\n<3> 提升%d点防御\n<Esc> 还是算了";

const wchar_t szStatus_Intro[]=			L"勇者去救公主。";
const wchar_t szStatus_Init[]=			L"<S>存档　　<L>读档　　<R>重置";
const wchar_t szStatus_Story[]=			L"剧情模式，按回车键继续。";

const wchar_t szStatus_UpStair[]=		L"你上楼了。";
const wchar_t szStatus_DownStair[]=		L"你下楼了。";
const wchar_t szStatus_WallCollapse[]=		L"墙倒了！";
const wchar_t szStatus_WallAppear[]=		L"地面变成了墙！";
const wchar_t szStatus_RedDoorOpen[]=		L"红门开了。";
const wchar_t szStatus_RedDoorBlock[]=		L"你没有红钥匙。";
const wchar_t szStatus_BlueDoorOpen[]=		L"蓝门开了。";
const wchar_t szStatus_BlueDoorBlock[]=		L"你没有蓝钥匙。";
const wchar_t szStatus_YellowDoorOpen[]=	L"黄门开了。";
const wchar_t szStatus_YellowDoorBlock[]=	L"你没有黄钥匙。";
const wchar_t szStatus_LavaBlock[]=		L"岩浆很热。";
const wchar_t szStatus_GetRedKey[]=		L"获得了一枚红钥匙。";
const wchar_t szStatus_GetBlueKey[]=		L"获得了一枚蓝钥匙。";
const wchar_t szStatus_GetYellowKey[]=		L"获得了一枚黄钥匙。";
const wchar_t szStatus_GetRedElixir[]=		L"获得了一瓶红药水，生命值增加了%d点。";
const wchar_t szStatus_GetBlueElixir[]=		L"获得了一瓶蓝药水，生命值增加了%d点。";
const wchar_t szStatus_GetRedCrystal[]=		L"获得了一颗红宝石，攻击力增加了%d点。";
const wchar_t szStatus_GetBlueCrystal[]=	L"获得了一颗蓝宝石，防御力增加了%d点。";
const wchar_t szStatus_GetWeapon[]=		L"获得了一把%s，攻击力增加了%d点。";
const wchar_t szStatus_GetArmor[]=		L"获得了一面%s，防御力增加了%d点。";
const wchar_t szStatus_GetItem[]=		L"获得了%s。";
const wchar_t szStatus_GetCross[]=		L"获得了十字架，对吸血鬼和僵尸的攻击力加倍。";
const wchar_t szStatus_GetDragonSlayer[]=	L"获得了屠龙刀，对龙的攻击力加倍。";
const wchar_t szStatus_GetLuckyGold[]=		L"获得了幸运金币。从现在开始获得的金币数加倍。";

const wchar_t szStatus_NewGame[]=		L"新游戏已开始。";
const wchar_t szStatus_LoadFile[]=		L"已读盘。";
const wchar_t szStatus_SaveFile[]=		L"已存盘。";
const wchar_t szStatus_Reset[]=			L"已重置。";
const wchar_t szStatus_Load[]=			L"已读档。";
const wchar_t szStatus_Save[]=			L"已存档。";
const wchar_t szStatus_SaveForbidden[]=		L"没有英雄之球不能存档。";
const wchar_t szStatus_OrbOfFlyingUsed[]=	L"使用飞行之球飞行。";
const wchar_t szStatus_OrbOfFlyingFailH[]=	L"这是你所到过的最高楼层。";
const wchar_t szStatus_OrbOfFlyingFailL[]=	L"这是你所到过的最低楼层。";
const wchar_t szStatus_OrbOfFlyingForbidden[]=	L"你必须站在楼梯旁才能飞行。";
const wchar_t szStatus_MagicElixirUsed[]=	L"使用了魔法药水，你的生命值增加了%d点。";
const wchar_t szStatus_MagicMattockUsed[]=	L"使用了镐，周围的墙已倒塌。";
const wchar_t szStatus_DestructibleBallUsed[]=	L"使用了炸弹，周围的敌人都死了，获得%d枚金币。";
const wchar_t szStatus_WarpStaffUsed[]=		L"你被传送了。";
const wchar_t szStatus_WarpStaffFail[]=		L"你不能被传送（目的地不是空地）。";
const wchar_t szStatus_WingsToFlyUpUsed[]=	L"使用了上升翼。";
const wchar_t szStatus_WingsToFlyUpFail[]=	L"无法上楼（目的地不是空地）。";
const wchar_t szStatus_WingsToFlyDownUsed[]=	L"使用了下降翼。";
const wchar_t szStatus_WingsToFlyDownFail[]=	L"无法下楼（目的地不是空地）。";
const wchar_t szStatus_SnowCrystalUsed[]=	L"使用了雪水晶，岩浆冷却成了石头。";
const wchar_t szStatus_MagicKeyUsed[]=		L"使用了魔法钥匙，本层的所有黄门都开了。";
const wchar_t szStatus_SuperMagicMattockUsed[]=	L"使用了超级镐，本层的所有墙都倒塌了。";

const wchar_t szStatus_BattleWinA[]=		L"你打败了%s，获得%d枚金币。";
const wchar_t szStatus_BattleWinD[]=		L"你成功防御了%s的进攻，获得%d枚金币。按回车键继续。";
const wchar_t szStatus_BattleLose[]=		L"你被%s击败了，游戏结束。";
const wchar_t szStatus_BattleForbidden[]=	L"你无法伤到%s，他的防御力太高了。";
const wchar_t szStatus_BattleEndless[]=		L"你与%s进入了无尽的战斗，按Esc投降。";
const wchar_t szStatus_BattleSurrender[]=	L"你投降了，游戏结束。";
const wchar_t szStatus_MagicAttack[]=		L"你受到了%d点魔法伤害。";
const wchar_t szStatus_MagicLose[]=		L"你被魔法击败了，游戏结束。";

const wchar_t szStatus_Merchant[]=		L"按1确认，按Esc取消。";
const wchar_t szStatus_Bought[]=		L"谢谢惠顾。";
const wchar_t szStatus_NoMoney[]=		L"你的钱不够。";
const wchar_t szStatus_NoKey[]=			L"你的黄钥匙不够。";
const wchar_t szStatus_Altar[]=			L"按数字键确认，按Esc取消。";
const wchar_t szStatus_OldMan2F[]=		L"你感到变得更强壮了。";
const wchar_t szStatus_Merchant2F[]=		L"获得了1000枚金币。";
const wchar_t szStatus_AltarLife[]=		L"生命值增加了%d点。";
const wchar_t szStatus_AltarAttack[]=		L"攻击力增加了%d点。";
const wchar_t szStatus_AltarDefend[]=		L"防御力增加了%d点。";
